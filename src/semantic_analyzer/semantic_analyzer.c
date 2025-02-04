/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semantic_analyzer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:16:14 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/03 12:15:39 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	create_cmds(t_astnode *root, t_list **cmds)
{
	if (!root)
		return ;
	create_cmds(root->left, cmds);
	create_cmds(root->right, cmds);
	if (root->type == ASTND_CMD)
		ft_lstadd_back(cmds, ft_lstnew(root));
	return ;
}

t_ex_astnode	*semantic_analyzer(t_astnode *root)
{
	t_astnode_type	type;
	t_ex_astnode	*node;
	t_astnode		*edge;

	if (!root)
		return (NULL);
	type = root->type;
	if (type == ASTND_PIPE || type == ASTND_CMD)
	{
		node = new_ex_astnode(EX_ASTND_PIPETOP);
		create_cmds(root, &(node->cmds));
		if (ft_lstlast(node->cmds))
		{
			edge = (t_astnode *)ft_lstlast(node->cmds)->content;
			edge->is_last_cmd = 1;
		}
		if (node->cmds)
		{
			edge = (t_astnode *)node->cmds->content;
			edge->is_first_cmd = 1;
		}
	}
	else
	{
		if (type == ASTND_OR)
		{
			node = new_ex_astnode(EX_ASTND_OR);
		}
		else if (type == ASTND_AND)
		{
			node = new_ex_astnode(EX_ASTND_AND);
		}
		else
		{
			dprintf(2, "Un Hundled Error\n");
			return (NULL);
		}
		node->left = semantic_analyzer(root->left);
		node->right = semantic_analyzer(root->right);
	}
	return (node);
}
