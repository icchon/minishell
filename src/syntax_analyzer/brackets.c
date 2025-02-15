/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:24:36 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/15 16:49:35 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax.h"

int	is_valid_brackets(char *line)
{
	int	cnt;
	int	i;

	keep_ascii(line, "()");
	cnt = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '(')
		{
			cnt++;
		}
		if (line[i] == ')')
		{
			cnt--;
		}
		if (cnt < 0)
			return (0);
		i++;
	}
	restore2d_ascii(line);
	return (cnt == 0);
}

int	count_brackets(t_token *tokens)
{
	t_token	*token;
	int		cnt;

	cnt = 0;
	token = tokens;
	while (token)
	{
		if (token->type == TK_BRA_RIGHT)
			cnt++;
		token = token->next;
	}
	return (cnt);
}

t_token	*get_kth_braleft_token(t_token *tokens, int k)
{
	t_token	*token;
	int		cnt;

	cnt = 0;
	token = tokens;
	while (token)
	{
		if (token->type == TK_BRA_LEFT)
			cnt++;
		if (cnt == k)
			return (token);
		token = token->next;
	}
	return (NULL);
}
