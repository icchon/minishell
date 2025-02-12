/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:58:48 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/12 08:48:28 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

pid_t	execute_command(t_astnode *root, int old_pipes[2], int new_pipes[2])
{
	t_astnode_type	type;
	pid_t			pid;

	if (!root)
		return (-1);
	type = root->type;
	if (type != ASTND_CMD)
		return (-1);
	expander(root);
	set_arginfo(root);
	pid = fork_and_exec_child(root, old_pipes, new_pipes);
	return (pid);
}

t_status	execute_one_builtin(t_astnode *root)
{
	t_status	status;
	int			stdin;
	int			stdout;

	expander(root);
	set_arginfo(root);
	if (!check_fds(root->redirects))
		return (EXIT_FAILURE);
	stdin = dup(STDIN_FILENO);
	stdout = dup(STDOUT_FILENO);
	handle_io(root->redirects);
	status = builtin(root->arg_strs);
	dup2(stdin, STDIN_FILENO);
	dup2(stdout, STDOUT_FILENO);
	close(stdin);
	close(stdout);
	return (status);
}

// void	close_pipes(int **pipes)
// {
// 	size_t	i;

// 	i = 1;
// 	while (pipes[i])
// 	{
// 		close(pipes[i][READ]);
// 		close(pipes[i][WRITE]);
// 		i++;
// 	}
// 	return ;
// }

t_status	execute_fork_commands(t_list *cmds)
{
	pid_t		*pids;
	int			i;
	int			**pipes;
	t_status	status;
	int			len;

	len = ft_lstsize(cmds);
	pids = (pid_t *)xmalloc(sizeof(pid_t) * len);
	pipes = create_pipes(len);
	i = 0;
	while (cmds)
	{
		pipe(pipes[i + 1]);
		pids[i] = execute_command(get_val(cmds), pipes[i], pipes[i + 1]);
		if (!get_val(cmds)->is_first_cmd)
		{
			close(pipes[i][READ]);
			close(pipes[i][WRITE]);
		}
		if (get_val(cmds)->is_last_cmd)
		{
			close(pipes[i + 1][READ]);
			close(pipes[i + 1][WRITE]);
		}
		cmds = cmds->next;
		i++;
	}
	// close_pipes(pipes);
	status = waitpids(len, pids);
	return (ft_2darraydel(pipes), free(pids), status);
}

t_status	execute_commands(t_list *cmds)
{
	t_astnode	*cmd;

	cmd = (t_astnode *)cmds->content;
	if (ft_lstsize(cmds) == 1 && is_builtin(cmd->args->data))
	{
		return (execute_one_builtin(cmd));
	}
	else
	{
		return (execute_fork_commands(cmds));
	}
	return (execute_fork_commands(cmds));
}

t_status	executer(t_ex_astnode *root)
{
	t_ex_astnode_type	type;
	t_status			left_status;

	if (!root)
		return (EXIT_SUCCESS);
	type = root->type;
	if (type == EX_ASTND_PIPETOP)
		return (execute_commands(root->cmds));
	else
	{
		left_status = executer(root->left);
		if (type == EX_ASTND_AND)
		{
			if (left_status == EXIT_SUCCESS)
				return (executer(root->right));
			return (left_status);
		}
		if (type == EX_ASTND_OR)
		{
			if (left_status != EXIT_SUCCESS)
				return (executer(root->right));
			return (left_status);
		}
	}
	return (EXIT_SUCCESS);
}
