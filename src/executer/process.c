#include "minishell.h"

static void	handle_io(t_token *redirect)
{
	int	fd;

	while (redirect)
	{
		if (redirect->type == TK_INPUT_FILE)
		{
			fd = open(redirect->data, O_RDONLY);
			dup2(fd, STDIN_FILENO);
		}
		else if (redirect->type == TK_OUTPUT_FILE)
		{
			fd = open(redirect->data, O_WRONLY | O_TRUNC | O_CREAT,
					S_IRGRP | S_IROTH | S_IWUSR | S_IRUSR);
			dup2(fd, STDOUT_FILENO);
		}
		else if (redirect->type == TK_OUTPUT_FILE_APPEND)
		{
			fd = open(redirect->data, O_WRONLY | O_APPEND | O_CREAT,
					S_IRGRP | S_IROTH | S_IWUSR | S_IRUSR);
			dup2(fd, STDOUT_FILENO);
		}
		close(fd);
		redirect = redirect->next;
	}
}

static int	try_command(char *cmd, char **arg, char **env)
{
	char	*path;

	path = ft_get_absolute_path(cmd, env);
	if (!(path && is_directory(path)))
	{
		free(path);
		return (EXIT_FAILURE);
	}
	if (access(path, X_OK) != 0)
	{
		free(path);
		return (EXIT_FAILURE);
	}
	execve(path, arg, env);
	return (EXIT_FAILURE);
}

static void	child_process(int old_pipes[2], int new_pipes[2], t_token *redirect,
		t_astnode *node)
{
	int	res;

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
	handle_io(redirect);
	res = try_command(node->cmd->data, node->arg_strs, grobal_env(GET, NULL));
	if (res == EXIT_FAILURE)
	{
		if (is_command(node->cmd->data))
			dprintf(2, "%s: command not found\n", node->cmd->data);
		else
			dprintf(2, "bash: %s: No such file or directory\n",
				node->cmd->data);
	}
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
