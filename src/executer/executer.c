/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:58:48 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/11 07:37:24 by kaisobe          ###   ########.fr       */
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

	expander(root);
	set_arginfo(root);
	status = check_fds(root->redirects);
	if (status != EXIT_SUCCESS)
	{
		return (EXIT_FAILURE);
	}
	return (builtin(root->arg_strs));
}

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
		cmds = cmds->next;
		i++;
	}
	status = waitpids(len, pids);
	return (ft_2darraydel(pipes), free(pids), status);
}

t_status	execute_commands(t_list *cmds)
{
	t_astnode	*cmd;
	t_status	status;

	cmd = (t_astnode *)cmds->content;
	if (ft_lstsize(cmds) == 1 && is_builtin(cmd->args->data))
	{
		status = execute_one_builtin(cmd);
		return (status);
	}
	else
	{
		return (execute_fork_commands(cmds));
	}
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
			if (left_status == EXIT_FAILURE)
				return (executer(root->right));
			return (left_status);
		}
	}
	return (EXIT_SUCCESS);
}
