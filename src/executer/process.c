/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:58:58 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/14 19:12:58 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void		sig_int_handler(int sig);
void		set_signal_child(void);

static int	try_command(char *cmd, char **arg, char **env)
{
	char	*path;

	if (is_directory(cmd) && contain_backslash(cmd))
	{
		ft_dprintf(STDERR_FILENO, "bash: %s: Is a directory\n", cmd);
		return (126);
	}
	path = ft_get_absolute_path(cmd, env);
	if (!(path && contain_backslash(path)))
	{
		free(path);
		if (!contain_backslash(cmd))
			ft_dprintf(STDERR_FILENO, "%s: command not found\n", cmd);
		else
			ft_dprintf(STDERR_FILENO, "bash: %s: No such file or directory\n",
				cmd);
		return (127);
	}
	if (!is_executable(path))
	{
		ft_dprintf(STDERR_FILENO, "bash: %s: Permission denied\n", cmd);
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
	if (!check_fds(redirect))
		exit(EXIT_FAILURE);
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
		set_signal_handlers(SIG_DFL, SIG_DFL);
		child_process(old_pipes, new_pipes, node->redirects, node);
	}
	return (pid);
}

// void	set_signal_child(void)
// {
// 	t_sigaction	act_c_child;
// 	t_sigaction	act_d_child;

// 	ft_bzero(&act_c_child, sizeof(t_sigaction));
// 	act_c_child.sa_handler = sig_int_handler;
// 	sigemptyset(&act_c_child.sa_mask);
// 	// act_c.sa_flags = SA_RESETHAND;
// 	sigaction(SIGINT, &act_c_child, NULL);
// 	ft_bzero(&act_d_child, sizeof(t_sigaction));
// 	act_d_child.sa_handler = SIG_IGN;
// 	sigemptyset(&act_d_child.sa_mask);
// 	// act_d.sa_flags = SA_RESETHAND;
// 	sigaction(SIGQUIT, &act_d_child, NULL);
// 	return ;
// }
