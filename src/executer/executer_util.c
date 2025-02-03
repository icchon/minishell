/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 10:28:56 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/03 12:19:07 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**create_args(t_astnode *node)
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

void	set_arginfo(t_astnode *node)
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

int	**create_pipes(int n)
{
	int	**out;
	int	i;

	out = (int **)malloc(sizeof(int *) * (n + 2));
	if (!out)
		return (NULL);
	i = 0;
	while (i < (n + 1))
	{
		out[i] = (int *)malloc(sizeof(int) * 2);
		if (!out[i])
		{
			ft_2darraydel(out);
			return (NULL);
		}
		out[i][READ] = -42;
		out[i][WRITE] = -42;
		i++;
	}
	out[i] = NULL;
	return (out);
}

pid_t	*create_pids(int n)
{
	pid_t	*out;

	out = (pid_t *)malloc(sizeof(pid_t) * (n + 1));
	if (!out)
		return (NULL);
	return (out);
}
