/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:03:03 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/13 15:16:01 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax.h"

int	analyze_redirect(t_token *token)
{
	t_token_type	type;

	type = token->type;
	if (type == TK_REDIN)
		if (!(token->next && token->next->type == TK_INFILE))
			return (0);
	if (type == TK_REDOUT)
		if (!(token->next && token->next->type == TK_OUTFILE))
			return (0);
	if (type == TK_REDOUT_APP)
		if (!(token->next && token->next->type == TK_OUTFILE_APP))
			return (0);
	if (type == TK_INFILE)
		if (!(token->prev && token->prev->type == TK_REDIN))
			return (0);
	if (type == TK_OUTFILE)
		if (!(token->prev && token->prev->type == TK_REDOUT))
			return (0);
	if (type == TK_OUTFILE_APP)
		if (!(token->prev && token->prev->type == TK_REDOUT_APP))
			return (0);
	return (1);
}

int	analyze_heredoc(t_token *token)
{
	t_token_type	type;

	type = token->type;
	if (type == TK_HEREDOC)
	{
		if (!(token->next && token->next->type == TK_LIMITER))
			return (0);
	}
	if (type == TK_LIMITER)
		if (!(token->prev && token->prev->type == TK_HEREDOC))
			return (0);
	return (1);
}

int	analyze_logical_op(t_token *token)
{
	t_token_type	type;

	type = token->type;
	if (type == TK_OR || type == TK_AND)
	{
		if (!(token->prev && token->next))
			return (0);
	}
	return (1);
}

int	analyze_pipe(t_token *token)
{
	t_token_type	type;

	type = token->type;
	if (type == TK_PIPE)
	{
		if (!(token->prev && token->next))
			return (0);
		token = token->next;
	}
	return (1);
}

int	analyze_simple_command(t_token *tokens)
{
	t_token			*token;
	int				word_cnt;
	t_token_type	type;

	word_cnt = 0;
	token = tokens;
	while (token)
	{
		type = token->type;
		if (type == TK_WORD || type == TK_VAR)
			word_cnt++;
		if (ft_ismatch(type, 3, TK_AND, TK_OR, TK_PIPE))
		{
			if (word_cnt == 0)
				return (0);
			word_cnt = 0;
		}
		token = token->next;
	}
	return (1);
}
