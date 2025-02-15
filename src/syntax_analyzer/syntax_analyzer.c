/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analyzer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:22:43 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/15 17:12:33 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax.h"

static int	type_match(char *data, int n, t_token_type type)
{
	int	i;

	if ((int)ft_strlen(data) != n)
	{
		return (0);
	}
	i = 0;
	while (i < n)
	{
		if ((int)data[i] != (int)(type % ASCII_SIZE))
			return (0);
		i++;
	}
	return (1);
}

int	analyze_simple_token(t_token *token)
{
	char			*data;
	t_token_type	type;
	int				res;

	data = token->data;
	keep_ascii(data, META);
	type = token->type;
	res = 1;
	if (type == TK_UNDEFINED)
		res = 0;
	if (ft_ismatch(type, 5, TK_WORD, TK_LIMITER, TK_INFILE, TK_OUTFILE,
			TK_OUTFILE_APP) && ft_contain_any(data, META))
		res = 0;
	if (type == TK_VAR && (ft_contain_any(data, META) || !(data[0] == '$')))
		res = 0;
	if (ft_ismatch(type, 5, TK_PIPE, TK_REDIN, TK_REDOUT, TK_BRA_LEFT,
			TK_BRA_RIGHT) && !type_match(data, 1, type))
		res = 0;
	if (ft_ismatch(type, 4, TK_OR, TK_AND, TK_HEREDOC, TK_REDOUT_APP)
		&& !type_match(data, 2, type))
		res = 0;
	restore2d_ascii(data);
	return (res);
}

static int	analyze_token_simple_func(t_token *tokens, t_analyze_f analyze_func)
{
	t_token	*token;

	token = tokens;
	while (token)
	{
		if (!analyze_func(token))
		{
			return (0);
		}
		token = token->next;
	}
	return (1);
}

int	syntax_analyzer(t_token *tokens)
{
	int	res;

	res = analyze_token_simple_func(tokens, (t_analyze_f)analyze_simple_token);
	res &= analyze_token_simple_func(tokens, (t_analyze_f)analyze_redirect);
	res &= analyze_token_simple_func(tokens, (t_analyze_f)analyze_heredoc);
	res &= analyze_token_simple_func(tokens, (t_analyze_f)analyze_pipe);
	res &= analyze_token_simple_func(tokens, (t_analyze_f)analyze_logical_op);
	res &= analyze_simple_command(tokens);
	res &= analyze_bracket_pairs(tokens);
	res &= analyze_bracket_connections(tokens);
	return (res);
}

// int	analyze_token_multiple_func(t_token *tokens, int argc, ...)
// {
// 	va_list		ap;
// 	t_analyze_f	analyze_func;
// 	int			i;

// 	va_start(ap, argc);
// 	i = 0;
// 	while (i < argc)
// 	{
// 		analyze_func = va_arg(ap, t_analyze_f);
// 		if (!analyze_token_simple_func(tokens, analyze_func))
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }