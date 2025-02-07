#include "minishell.h"

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

t_status	execute_one_builtin(t_astnode *root)
{
	expander(root);
	set_arginfo(root);
	return (builtin(root->arg_strs));
}

int	execute_commands(t_list *cmds)
{
	t_astnode	*cmd;
	t_list		*node;
	pid_t		*pids;
	t_status	status;
	int			i;
	int			**pipes;

	cmd = (t_astnode *)cmds->content;
	if (ft_lstsize(cmds) == 1 && is_builtin(cmd->args->data))
	{
		status = execute_one_builtin(cmd);
		grobal_status(SET, status);
		return (status);
	}
	pids = create_pids(ft_lstsize(cmds));
	pipes = create_pipes(ft_lstsize(cmds));
	status = 1;
	node = cmds;
	i = 0;
	while (node)
	{
		cmd = (t_astnode *)node->content;
		pipe(pipes[i + 1]);
		pids[i] = execute_command(cmd, pipes[i], pipes[i + 1]);
		if (!cmd->is_first_cmd)
		{
			close(pipes[i][READ]);
			close(pipes[i][WRITE]);
		}
		node = node->next;
		i++;
	}
	i = 0;
	while (i < ft_lstsize(cmds))
	{
		waitpid(pids[i++], (int *)&(status), 0);
		grobal_status(SET, status);
	}
	ft_2darraydel(pipes);
	free(pids);
	return (status);
}

t_status	executer(t_ex_astnode *root)
{
	t_ex_astnode_type	type;
	t_status			left_status;

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
				return (executer(root->right));
			}
			return (left_status);
		}
		if (type == EX_ASTND_OR)
		{
			if (left_status == EXIT_FAILURE)
			{
				return (executer(root->right));
			}
			return (left_status);
		}
	}
	return (EXIT_FAILURE);
}
