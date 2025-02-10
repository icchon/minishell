/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semantic_analyzer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:23:02 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/10 15:23:03 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	create_cmds(t_astnode *root, t_list **cmds)
{
	if (!root)
		return ;
	create_cmds(root->left, cmds);
	create_cmds(root->right, cmds);
	if (root->type == ASTND_CMD)
		ft_lstadd_back(cmds, ft_lstnew(root));
	return ;
}

static void	set_command_order_flg(t_ex_astnode *node)
{
	t_astnode	*edge;

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
	return ;
}

t_ex_astnode	*semantic_analyzer(t_astnode *root)
{
	t_astnode_type	type;
	t_ex_astnode	*node;

	if (!root)
		return (NULL);
	type = root->type;
	if (type == ASTND_PIPE || type == ASTND_CMD)
	{
		node = new_ex_astnode(EX_ASTND_PIPETOP);
		create_cmds(root, &(node->cmds));
		set_command_order_flg(node);
	}
	else
	{
		if (type == ASTND_OR)
			node = new_ex_astnode(EX_ASTND_OR);
		else
			node = new_ex_astnode(EX_ASTND_AND);
		node->left = semantic_analyzer(root->left);
		node->right = semantic_analyzer(root->right);
	}
	return (node);
}
