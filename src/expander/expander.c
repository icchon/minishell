/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:11:40 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/13 15:38:24 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

void	expand_args(t_astnode *node)
{
	t_token	*token;
	char	*tmp;
	t_token	*new_tokens;
	t_token	*to_add;
	t_token	*to_delete;

	token = node->args;
	node->args = NULL;
	while (token)
	{
		if (token->type == TK_VAR)
		{
			new_tokens = token_variable_split(&token);
			to_delete = token;
			token = token->next;
			cut_token(&to_delete, to_delete);
			addback_tokens(&node->args, new_tokens);
			continue ;
		}
		tmp = token->data;
		token->data = expand_word(tmp);
		to_add = token;
		token = token->next;
		addback_token(&node->args, (free(tmp), to_add));
	}
}

void	expand_redirects(t_astnode *node)
{
	t_token	*token;
	char	*tmp;
	t_token	*new_tokens;
	t_token	*to_add;
	t_token	*to_delete;

	token = node->redirects;
	node->redirects = NULL;
	while (token)
	{
		if (token->type == TK_VAR)
		{
			new_tokens = token_variable_split(&token);
			to_delete = token;
			token = token->next;
			cut_token(&to_delete, to_delete);
			addback_tokens(&node->redirects, new_tokens);
			continue ;
		}
		tmp = token->data;
		token->data = expand_word(tmp);
		to_add = token;
		token = token->next;
		addback_token(&node->redirects, (free(tmp), to_add));
	}
}

void	expander(t_astnode *node)
{
	if (!node)
		return ;
	expand_args(node);
	expand_redirects(node);
	expander(node->left);
	expander(node->right);
}
