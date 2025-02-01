/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 13:45:25 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/01 17:48:04 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**create_args(t_astnode *node)
{
	char	**out;
	t_arg	*arg;
	size_t	arg_len;
	size_t	i;

	if (!node)
		return (NULL);
	arg_len = size_token(node->args);
	i = 1;
	arg = node->args;
	out = (char **)malloc(sizeof(char *) * (arg_len + 2));
	if (!out)
		return (NULL);
	out[0] = node->cmd->data;
	while (arg)
	{
		out[i++] = arg->data;
		arg = arg->next;
	}
	out[arg_len + 1] = NULL;
	return (out);
}

static void	set_arginfo(t_astnode *node)
{
	if (!node)
		return ;
	if (node->args)
	{
		node->arg_cnt = size_token(node->args);
		node->arg_strs = create_args(node);
	}
	return ;
}

t_pids	*new_pids(pid_t pid)
{
	t_pids	*lst;

	lst = (t_pids *)malloc(sizeof(t_pids));
	if (lst)
	{
		lst->pid = pid;
		lst->next = NULL;
	}
	return (lst);
}

void	print_pids(t_pids *pids)
{
	t_pids	*node;

	node = pids;
	while (node)
	{
		dprintf(2, "pid : %d\n", node->pid);
		node = node->next;
	}
	return ;
}

t_pids	*last_pid(t_pids *lst)
{
	t_pids	*last;

	if (!lst)
		return (NULL);
	last = lst;
	while (last->next)
		last = last->next;
	return (last);
}

void	addback_pid(t_pids **lst, t_pids *newpid)
{
	t_pids	*last;

	last = last_pid(*lst);
	newpid->next = NULL;
	if (!last)
	{
		*lst = newpid;
	}
	else
	{
		last->next = newpid;
	}
}

pid_t	execute_cmd(t_astnode *root)
{
	t_astnode_type	type;
	pid_t			pid;

	if (!root)
	{
		dprintf(2, "root is null\n");
		return (-1);
	}
	type = root->type;
	if (type != ASTND_CMD)
	{
		dprintf(2, "NOT ASTND_CMD\n");
		return (-1);
	}
	expander(root);
	set_arginfo(root);
	pid = exec_command(root);
	return (pid);
}

void	execute_pipe(t_astnode *root, t_pids **pids)
{
	t_astnode_type	type;
	t_astnode		*left;
	t_astnode		*right;

	if (!root)
	{
		dprintf(2, "root is null\n");
		return ;
	}
	type = root->type;
	if (type != ASTND_PIPE)
	{
		dprintf(2, "not ASTND_PIPE\n");
		return ;
	}
	left = root->left;
	right = root->right;
	if (left)
	{
		if (left->type == ASTND_CMD)
		{
			addback_pid(pids, new_pids(execute_cmd(left)));
		}
		else if (left->type == ASTND_PIPE)
		{
			execute_pipe(left, pids);
		}
		else
		{
			dprintf(2, "Un Hundled Error\n");
		}
	}
	if (right)
	{
		if (right->type == ASTND_CMD)
		{
			addback_pid(pids, new_pids(execute_cmd(right)));
		}
		else if (right->type == ASTND_PIPE)
		{
			execute_pipe(right, pids);
		}
		else
		{
			dprintf(2, "Un Hundled Error\n");
		}
	}
	return ;
}

int	contain_logical_op(t_astnode *root)
{
	t_astnode	*left;
	t_astnode	*right;

	if (!root)
	{
		return (0);
	}
	if (root->type == ASTND_AND || root->type == ASTND_OR)
	{
		return (1);
	}
	left = root->left;
	right = root->right;
	return (contain_logical_op(left) || contain_logical_op(right));
}

int	pids_size(t_pids *pids)
{
	t_pids	*node;
	int		ans;

	ans = 0;
	node = pids;
	while (node)
	{
		ans++;
		node = node->next;
	}
	return (ans);
}

void	execute_parent(t_astnode *root)
{
	t_pids			*pids;
	t_astnode_type	type;
	t_pids			*new;
	pid_t			pid;
	t_pids			*node;
	int				status;

	pids = NULL;
	if (!root)
	{
		return ;
	}
	type = root->type;
	if (type == ASTND_CMD)
	{
		pid = exec_command(root);
		new = new_pids(pid);
		addback_pid(&pids, new);
	}
	else if (type == ASTND_PIPE)
	{
		execute_pipe(root, &pids);
	}
	node = pids;
	read_and_print();
	while (node)
	{
		waitpid(node->pid, &status, 0);
		node = node->next;
	}
	return ;
}

void	executer(t_astnode *root)
{
	// t_astnode_type	type;
	if (!root)
		return ;
	// type = root->type;
	check_fds(root);
	execute_parent(root);
	return ;
}
