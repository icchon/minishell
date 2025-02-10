/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_token_util2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:20:13 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/10 15:20:33 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	size_token(t_token *token)
{
	t_token	*node;
	size_t	cnt;

	node = token;
	cnt = 0;
	while (node)
	{
		node = node->next;
		cnt++;
	}
	return (cnt);
}

void	free_token(t_token *token)
{
	if (!token)
		return ;
	free(token->data);
	free(token);
	return ;
}

void	cut_token(t_token **token, t_token *to_delete)
{
	t_token	*prev;
	t_token	*next;

	if (!to_delete)
		return ;
	prev = to_delete->prev;
	next = to_delete->next;
	if (prev)
		prev->next = NULL;
	if (next)
		next->prev = NULL;
	free_token(to_delete);
	if (!prev && !next)
		*token = NULL;
	return ;
}

void	free_tokens(t_token *token)
{
	t_token	*node;
	t_token	*next;

	node = token;
	while (node)
	{
		next = node->next;
		free_token(node);
		node = next;
	}
	return ;
}
