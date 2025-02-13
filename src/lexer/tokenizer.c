/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:20:19 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/13 15:33:41 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

static void	set_tokens(t_token *current, t_token_type type1, t_token *next,
		t_token_type type2)
{
	if (current)
	{
		if (type1 == TK_WORD && current->data && current->data[0] == '$')
			type1 = TK_VAR;
		current->type = type1;
	}
	if (next)
	{
		if (type2 == TK_WORD && next->data && next->data[0] == '$')
			type2 = TK_VAR;
		next->type = type2;
	}
	return ;
}

static void	set_type(t_token *token)
{
	if (token->type != TK_UNDEFINED)
		return ;
	else if (ft_isequal(token->data, "<<"))
		set_tokens(token, TK_HEREDOC, token->next, TK_LIMITER);
	else if (ft_isequal(token->data, ">>"))
		set_tokens(token, TK_REDOUT_APP, token->next, TK_OUTFILE_APP);
	else if (ft_isequal(token->data, "||"))
		set_tokens(token, TK_OR, NULL, TK_UNDEFINED);
	else if (ft_isequal(token->data, "&&"))
		set_tokens(token, TK_AND, NULL, TK_UNDEFINED);
	else if (ft_isequal(token->data, ">"))
		set_tokens(token, TK_REDOUT, token->next, TK_OUTFILE);
	else if (ft_isequal(token->data, "<"))
		set_tokens(token, TK_REDIN, token->next, TK_INFILE);
	else if (ft_isequal(token->data, "|"))
		set_tokens(token, TK_PIPE, NULL, TK_UNDEFINED);
	else if (ft_isequal(token->data, "("))
		set_tokens(token, TK_BRA_LEFT, NULL, TK_UNDEFINED);
	else if (ft_isequal(token->data, ")"))
		set_tokens(token, TK_BRA_RIGHT, NULL, TK_UNDEFINED);
	else
		set_tokens(token, TK_WORD, NULL, TK_UNDEFINED);
}

void	tokenizer(t_token *tokens)
{
	t_token	*token;

	if (!tokens)
		return ;
	token = tokens;
	while (token)
	{
		set_type(token);
		token = token->next;
	}
	return ;
}
