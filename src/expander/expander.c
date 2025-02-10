/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:11:40 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/11 07:36:58 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

char	*expand_word(char *str)
{
	int		is_single;
	int		is_double;
	char	*out;
	char	*tmp;

	is_single = is_single_quate(str);
	is_double = is_double_quate(str);
	if (is_single)
	{
		out = trim_quate(str);
	}
	else if (is_double)
	{
		tmp = trim_quate(str);
		out = replace_env_vars(tmp);
		free(tmp);
	}
	else
	{
		out = replace_env_vars(str);
	}
	return (out);
}

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
		if (token->type == TK_VALIABLE)
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
	t_token	*to_add;

	token = node->redirects;
	node->redirects = NULL;
	while (token)
	{
		tmp = token->data;
		token->data = expand_word(tmp);
		to_add = token;
		token = token->next;
		addback_token(&node->redirects, to_add);
		free(tmp);
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
