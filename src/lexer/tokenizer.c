/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:20:19 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/11 07:36:21 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

static void	set_tokens(t_token *current, t_token_type type1, t_token *next,
		t_token_type type2)
{
	if (current)
	{
		if (type1 == TK_WORD && current->data && current->data[0] == '$')
			type1 = TK_VALIABLE;
		current->type = type1;
	}
	if (next)
	{
		if (type2 == TK_WORD && next->data && next->data[0] == '$')
			type2 = TK_VALIABLE;
		next->type = type2;
	}
	return ;
}

static void	set_type(t_token **current, t_token **next, t_token **prev)
{
	if ((*current)->type != TK_UNDEFINED)
	{
		*current = *next;
		*next = (*current)->next;
		*prev = (*current)->prev;
		return ;
	}
	else if (ft_isequal((*current)->data, "<<"))
		set_tokens(*current, TK_HERE_DOC, *next, TK_LIMITER);
	else if (ft_isequal((*current)->data, ">>"))
		set_tokens(*current, TK_REDIRECT_OUT_APPEND, *next,
			TK_OUTPUT_FILE_APPEND);
	else if (ft_isequal((*current)->data, "||"))
		set_tokens(*current, TK_OR, NULL, TK_UNDEFINED);
	else if (ft_isequal((*current)->data, "&&"))
		set_tokens(*current, TK_AND, NULL, TK_UNDEFINED);
	else if (ft_isequal((*current)->data, ">"))
		set_tokens(*current, TK_REDIRECT_OUT, *next, TK_OUTPUT_FILE);
	else if (ft_isequal((*current)->data, "<"))
		set_tokens(*current, TK_REDIRECT_IN, *next, TK_INPUT_FILE);
	else if (ft_isequal((*current)->data, "|"))
		set_tokens(*current, TK_PIPE, *next, TK_WORD);
	else
		set_tokens(*current, TK_WORD, NULL, TK_UNDEFINED);
}

void	tokenizer(t_token **token_ptr)
{
	t_token	*current;
	t_token	*next;
	t_token	*prev;

	if (!(*token_ptr))
		return ;
	current = head_token(*token_ptr);
	next = current->next;
	while (next)
	{
		set_type(&current, &next, &prev);
	}
	if (current->type == TK_UNDEFINED)
		set_tokens(current, TK_WORD, NULL, TK_UNDEFINED);
	return ;
}
