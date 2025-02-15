/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:27:27 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/15 16:19:42 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

static t_astnode	*parse_brackets(t_token **token)
{
	t_token	*to_delete;
	t_token	*parts;
	int		bracket_cnt;

	bracket_cnt = 1;
	if (!(*token && (*token)->type == TK_BRA_LEFT))
		return (NULL);
	to_delete = *token;
	*token = (*token)->next;
	parts = *token;
	cut_token(token, to_delete);
	while (1)
	{
		if ((*token)->type == TK_BRA_LEFT)
			bracket_cnt++;
		if ((*token)->type == TK_BRA_RIGHT)
			bracket_cnt--;
		if (bracket_cnt == 0)
			break ;
		(*token) = (*token)->next;
	}
	to_delete = *token;
	(*token) = (*token)->next;
	cut_token(token, to_delete);
	return (parse_or_and(&parts));
}

static t_astnode	*parse_cmd(t_token **token)
{
	t_astnode	*node;

	if (!*token)
		return (NULL);
	if ((*token)->type == TK_BRA_LEFT)
	{
		return (parse_brackets(token));
	}
	node = new_astnode();
	create_node_prop(node, token);
	return (node);
}

static t_astnode	*parse_pipe(t_token **token)
{
	t_astnode	*left;
	t_astnode	*root;
	t_astnode	*right;
	t_token		*to_delete;

	left = parse_cmd(token);
	if (!left)
		return (NULL);
	while (*token && ((*token)->type == TK_PIPE))
	{
		root = new_astnode();
		root->type = ASTND_PIPE;
		to_delete = (*token);
		(*token) = (*token)->next;
		cut_token(token, to_delete);
		right = parse_cmd(token);
		if (!right)
			return (NULL);
		root->left = left;
		root->right = right;
		left = root;
	}
	return (left);
}

t_astnode	*parse_or_and(t_token **token)
{
	t_astnode	*root;
	t_astnode	*left;
	t_token		*to_delete;

	left = parse_pipe(token);
	while (*token && ((*token)->type == TK_OR || (*token)->type == TK_AND))
	{
		root = new_astnode();
		if ((*token)->type == TK_OR)
			root->type = ASTND_OR;
		else
			root->type = ASTND_AND;
		to_delete = (*token);
		(*token) = (*token)->next;
		cut_token(token, to_delete);
		root->right = parse_pipe(token);
		if (!root->right)
			return (left);
		root->left = left;
		left = root;
	}
	return (left);
}
