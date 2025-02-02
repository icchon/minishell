/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exast_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:47:48 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/02 14:54:14 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ex_astnode	*new_ex_astnode(t_ex_astnode_type type)
{
	t_ex_astnode	*ex_astnode;

	ex_astnode = (t_ex_astnode *)malloc(sizeof(t_ex_astnode));
	if (!ex_astnode)
		return (NULL);
	ex_astnode->type = type;
	ex_astnode->cmds = NULL;
	ex_astnode->left = NULL;
	ex_astnode->right = NULL;
	return (ex_astnode);
}

static void	print_ex_astnode(t_ex_astnode *node, int depth)
{
	t_list	*cmd;
	int		i;

	if (!node)
		return ;
	i = 0;
	while (i++ < depth)
		dprintf(2, "  ");
	if (node->type == EX_ASTND_OR)
		dprintf(2, "OR\n");
	else if (node->type == EX_ASTND_AND)
		dprintf(2, "AND\n");
	else if (node->type == EX_ASTND_PIPETOP)
	{
		dprintf(2, "PIPETOP\n");
		cmd = node->cmds;
		while (cmd)
		{
			i = 0;
			while (i++ < depth + 1)
				dprintf(2, "  ");
			print_cmd((t_astnode *)cmd->content, depth);
			cmd = cmd->next;
		}
	}
	else
		dprintf(2, "UNDEFINED\n");
	print_ex_astnode(node->left, depth + 1);
	print_ex_astnode(node->right, depth + 1);
}

void	print_ex_tree(t_ex_astnode *root)
{
	dprintf(2, "\n[EX TREE] \n");
	if (!root)
		dprintf(2, "NULL\n");
	print_ex_astnode(root, 0);
	dprintf(2, "\n");
}
