/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:58:58 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/10 15:03:57 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	try_command(char *cmd, char **arg, char **env)
{
	char	*path;

	if (is_directory(cmd) && contain_backslash(cmd))
	{
		dprintf(2, "bash: %s: Is a directory\n", cmd);
		return (126);
	}
	path = ft_get_absolute_path(cmd, env);
	if (!(path && contain_backslash(path)))
	{
		free(path);
		if (!contain_backslash(cmd))
			dprintf(2, "%s: command not found\n", cmd);
		else
			dprintf(2, "bash: %s: No such file or directory\n", cmd);
		return (127);
	}
	if (!is_executable(path))
	{
		dprintf(2, "bash: %s: Permission denied\n", path);
		return (126);
	}
	return (execve(path, arg, env));
}

static void	child_process(int old_pipes[2], int new_pipes[2], t_token *redirect,
		t_astnode *node)
{
	t_status	status;

	if (!node->is_first_cmd)
	{
		close(old_pipes[WRITE]);
		dup2(old_pipes[READ], STDIN_FILENO);
		close(old_pipes[READ]);
	}
	if (!node->is_last_cmd)
	{
		close(new_pipes[READ]);
		dup2(new_pipes[WRITE], STDOUT_FILENO);
		close(new_pipes[WRITE]);
	}
	status = check_fds(redirect);
	if (status != EXIT_SUCCESS)
	{
		exit(EXIT_FAILURE);
	}
	handle_io(redirect);
	if (is_builtin(node->args->data))
		status = builtin(node->arg_strs);
	else
		status = try_command(node->args->data, node->arg_strs, grobal_env(GET));
	exit(status);
}

pid_t	fork_and_exec_child(t_astnode *node, int old_pipes[2], int new_pipes[2])
{
	pid_t	pid;

	pid = fork();
	if (pid == CHILD_PID)
	{
		child_process(old_pipes, new_pipes, node->redirects, node);
	}
	return (pid);
}
