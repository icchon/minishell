/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 13:45:25 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/02 20:46:43 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static void	print_arr(int *arr, int n)
// {
// 	int	i;

// 	i = 0;
// 	while (i < n)
// 	{
// 		dprintf(2, "%d ", arr[i]);
// 		i++;
// 	}
// 	dprintf(2, "\n");
// }

// static void	print_arrs(int **arrs)
// {
// 	int	i;

// 	i = 0;
// 	while (arrs[i])
// 	{
// 		print_arr(arrs[i], 2);
// 		i++;
// 	}
// }

pid_t	execute_command(t_astnode *root, int old_pipes[2], int new_pipes[2])
{
	t_astnode_type	type;
	pid_t			pid;

	if (!root)
		return (dprintf(2, "root is null\n"), -1);
	type = root->type;
	if (type != ASTND_CMD)
		return (dprintf(2, "NOT ASTND_CMD\n"), -1);
	expander(root);
	set_arginfo(root);
	pid = fork_and_exec_child(root, old_pipes, new_pipes);
	return (pid);
}

int	execute_commands(t_list *cmds)
{
	t_astnode	*cmd;
	t_list		*node;
	pid_t		*pids;
	int			status;
	int			i;
	int			**pipes;

	pids = create_pids(ft_lstsize(cmds));
	pipes = create_pipes(ft_lstsize(cmds));
	status = 1;
	node = cmds;
	i = 0;
	while (node)
	{
		cmd = (t_astnode *)node->content;
		pids[i] = execute_command(cmd, pipes[i], pipes[i + 1]);
		if (!cmd->is_last_cmd)
		{
			close(pipes[i + 1][WRITE]);
			dup2(pipes[i + 1][READ], STDIN_FILENO);
			close(pipes[i + 1][READ]);
		}
		node = node->next;
		i++;
	}
	i = 0;
	while (i < ft_lstsize(cmds))
	{
		waitpid(pids[i++], &status, 0);
	}
	return (status);
}

int	executer(t_ex_astnode *root)
{
	t_ex_astnode_type	type;
	int					left_status;

	if (!root)
		return (EXIT_FAILURE);
	type = root->type;
	if (type == EX_ASTND_PIPETOP)
	{
		return (execute_commands(root->cmds));
	}
	else
	{
		left_status = executer(root->left);
		if (type == EX_ASTND_AND)
		{
			if (left_status == EXIT_SUCCESS)
			{
				executer(root->right);
			}
		}
		if (type == EX_ASTND_OR)
		{
			if (left_status == EXIT_FAILURE)
			{
				executer(root->right);
			}
		}
	}
	executer(root->left);
	return (executer(root->right));
}
