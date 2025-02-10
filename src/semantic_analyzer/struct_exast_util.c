/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_exast_util.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:23:12 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/10 15:30:33 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ex_astnode	*new_ex_astnode(t_ex_astnode_type type)
{
	t_ex_astnode	*ex_astnode;

	ex_astnode = (t_ex_astnode *)xmalloc(sizeof(t_ex_astnode));
	ex_astnode->type = type;
	ex_astnode->cmds = NULL;
	ex_astnode->left = NULL;
	ex_astnode->right = NULL;
	return (ex_astnode);
}

void	free_cmds(t_list *cmds)
{
	t_list	*tmp;
	t_list	*node;

	node = cmds;
	while (node)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
}

void	free_ex_asttree(t_ex_astnode *node)
{
	if (!node)
		return ;
	free_ex_asttree(node->left);
	free_ex_asttree(node->right);
	free_cmds(node->cmds);
	node->cmds = NULL;
	free(node);
}

// static void	print_ex_astnode(t_ex_astnode *node, int depth)
// {
// 	t_list	*cmd;
// 	int		i;

// 	if (!node)
// 		return ;
// 	i = 0;
// 	while (i++ < depth)
// 		dprintf(2, "  ");
// 	if (node->type == EX_ASTND_OR)
// 		dprintf(2, "OR\n");
// 	else if (node->type == EX_ASTND_AND)
// 		dprintf(2, "AND\n");
// 	else if (node->type == EX_ASTND_PIPETOP)
// 	{
// 		dprintf(2, "PIPETOP\n");
// 		cmd = node->cmds;
// 		while (cmd)
// 		{
// 			i = 0;
// 			while (i++ < depth + 1)
// 				dprintf(2, "  ");
// 			print_cmd((t_astnode *)cmd->content, depth);
// 			cmd = cmd->next;
// 		}
// 	}
// 	else
// 		dprintf(2, "UNDEFINED\n");
// 	print_ex_astnode(node->left, depth + 1);
// 	print_ex_astnode(node->right, depth + 1);
// }

// void	print_ex_tree(t_ex_astnode *root)
// {
// 	dprintf(2, "\n[EX TREE] \n");
// 	if (!root)
// 		dprintf(2, "NULL\n");
// 	print_ex_astnode(root, 0);
// 	dprintf(2, "\n");
// }
