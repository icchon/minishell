/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bracket_analyze_func.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:45:50 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/15 16:53:14 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax.h"

static int	analyze_bracket(t_token *braleft_token)
{
	int		bracket_cnt;
	int		cmd_cnt;
	t_token	*token;

	bracket_cnt = 0;
	cmd_cnt = 0;
	token = braleft_token;
	while (token)
	{
		if (token->type == TK_WORD || token->type == TK_VAR)
			cmd_cnt++;
		if (token->type == TK_BRA_LEFT)
			bracket_cnt++;
		if (token->type == TK_BRA_RIGHT)
			bracket_cnt--;
		if (bracket_cnt == 0)
		{
			if (cmd_cnt == 0)
				return (0);
			break ;
		}
		token = token->next;
	}
	return (1);
}

int	analyze_bracket_pairs(t_token *tokens)
{
	int		i;
	t_token	*braleft_token;

	i = 0;
	while (i < count_brackets(tokens))
	{
		braleft_token = get_kth_braleft_token(tokens, (i + 1));
		if (!analyze_bracket(braleft_token))
			return (0);
		i++;
	}
	return (1);
}

static int	is_op_token(t_token *token)
{
	t_token_type	type;

	if (!token)
		return (0);
	type = token->type;
	return (ft_ismatch(type, 3, TK_PIPE, TK_OR, TK_AND));
}

static int	analyze_bracket_connection(t_token *braleft_token)
{
	int		op_cnt;
	int		bracket_cnt;
	t_token	*token;

	op_cnt = 0;
	bracket_cnt = 0;
	token = braleft_token;
	while (token)
	{
		if (token->type == TK_BRA_LEFT)
			bracket_cnt++;
		if (token->type == TK_BRA_RIGHT)
			bracket_cnt--;
		if (bracket_cnt == 0)
			break ;
		token = token->next;
	}
	if (!token->next)
		return (1);
	return (is_op_token(token->next));
}

int	analyze_bracket_connections(t_token *tokens)
{
	int		i;
	t_token	*braleft_token;

	i = 0;
	while (i < count_brackets(tokens))
	{
		braleft_token = get_kth_braleft_token(tokens, (i + 1));
		if (!analyze_bracket_connection(braleft_token))
			return (0);
		i++;
	}
	return (1);
}
