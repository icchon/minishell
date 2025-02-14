/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:58:48 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/15 08:16:04 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void	close_pipes(int **pipes, int i, t_list *cmd)
{
	if (!get_val(cmd)->is_first_cmd)
	{
		close(pipes[i][READ]);
		close(pipes[i][WRITE]);
	}
	if (get_val(cmd)->is_last_cmd)
	{
		close(pipes[i + 1][READ]);
		close(pipes[i + 1][WRITE]);
	}
	return ;
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
		pids[i] = execute_simple_command(get_val(cmds), pipes[i], pipes[i + 1]);
		close_pipes(pipes, i, cmds);
		cmds = cmds->next;
		i++;
	}
	status = waitpids(len, pids);
	return (ft_2darraydel(pipes), free(pids), status);
}

t_status	execute_commands(t_list *cmds)
{
	t_astnode	*cmd;

	cmd = (t_astnode *)cmds->content;
	update_grobal_env();
	if (ft_lstsize(cmds) == 1 && is_builtin(cmd->args->data))
	{
		return (execute_single_builtin(cmd));
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
