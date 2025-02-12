/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_ast_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:22:19 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/12 07:28:46 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

t_astnode	*new_astnode(void)
{
	t_astnode	*node;

	node = (t_astnode *)xmalloc(sizeof(t_astnode));
	node->arg_cnt = 0;
	node->args = NULL;
	node->left = NULL;
	node->right = NULL;
	node->type = ASTND_UNDEFINED;
	node->redirects = NULL;
	node->arg_strs = NULL;
	node->is_last_cmd = 0;
	node->is_first_cmd = 0;
	return (node);
}

void	free_astnode(t_astnode *node)
{
	if (!node)
		return ;
	free_tokens(node->args);
	free_tokens(node->redirects);
	free(node->arg_strs);
	free(node);
}

void	free_asttree(t_astnode *root)
{
	t_astnode	*left;
	t_astnode	*right;

	if (!root)
		return ;
	left = root->left;
	right = root->right;
	free_astnode(root);
	free_asttree(left);
	free_asttree(right);
	return ;
}

void	add_astnode(t_astnode **root, t_astnode *left, t_astnode *right)
{
	if (*root == NULL)
	{
		*root = new_astnode();
		if (!*root)
			return ;
	}
	(*root)->left = left;
	(*root)->right = right;
	return ;
}

t_astnode	*get_val(t_list *lst)
{
	if (!lst)
		return (NULL);
	return ((t_astnode *)lst->content);
}

void	print_cmd(t_astnode *cmd_node, int depth)
{
	t_arg		*arg;
	t_redirect	*red;
	int			i;

	dprintf(2, "CMD: %s\n", cmd_node->args->data);
	arg = cmd_node->args;
	arg = arg->next;
	while (arg)
	{
		i = 0;
		while (i++ < depth + 2)
			dprintf(2, "  ");
		dprintf(2, "ARG: %s\n", arg->data);
		arg = arg->next;
	}
	red = cmd_node->redirects;
	while (red)
	{
		i = 0;
		while (i++ < depth)
			dprintf(2, "  ");
		if (red->type == TK_INPUT_FILE)
			dprintf(2, "  REDIRECT < %s\n", red->data);
		else if (red->type == TK_OUTPUT_FILE)
			dprintf(2, "  REDIRECT > %s\n", red->data);
		else if (red->type == TK_LIMITER)
			dprintf(2, "  HERE_DOC LIMITER : %s\n", red->data);
		else
			dprintf(2, "  REDIRECT >> %s\n", red->data);
		red = red->next;
	}
}

static void	print_astnode(t_astnode *node, int depth)
{
	int	i;

	if (!node)
		return ;
	i = 0;
	while (i++ < depth)
		dprintf(2, "  ");
	if (node->type == ASTND_PIPE)
		dprintf(2, "PIPE\n");
	else if (node->type == ASTND_OR)
		dprintf(2, "OR\n");
	else if (node->type == ASTND_AND)
		dprintf(2, "AND\n");
	else if (node->type == ASTND_CMD)
		print_cmd(node, depth);
	else
		dprintf(2, "UNDEFINED\n");
	print_astnode(node->left, depth + 1);
	print_astnode(node->right, depth + 1);
}

void	print_tree(t_astnode *root)
{
	dprintf(2, "\n[AST TREE]\n");
	if (!root)
		dprintf(2, "NULL\n");
	print_astnode(root, 0);
	dprintf(2, "\n");
}
