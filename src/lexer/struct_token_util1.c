/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_token_util1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:20:11 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/11 07:36:02 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

t_token	*new_token(t_token_type type, char *data)
{
	t_token	*token;

	token = (t_token *)xmalloc(sizeof(t_token));
	token->type = type;
	token->data = data;
	token->prev = NULL;
	token->next = NULL;
	return (token);
}

t_token	*last_token(t_token *token)
{
	t_token	*node;

	if (token == NULL)
		return (token);
	node = token;
	while (node->next != NULL)
	{
		node = node->next;
	}
	return (node);
}

void	addback_token(t_token **token, t_token *new)
{
	t_token	*last_node;

	if (!new)
		return ;
	last_node = last_token(*token);
	new->next = NULL;
	new->prev = last_node;
	if (last_node == NULL)
	{
		*token = new;
		return ;
	}
	last_node->next = new;
	return ;
}

void	addfront_token(t_token **token, t_token *new)
{
	if (new == NULL)
		return ;
	new->next = *token;
	new->prev = NULL;
	if (*token != NULL)
		(*token)->prev = new;
	*token = new;
}

t_token	*head_token(t_token *token)
{
	t_token	*node;

	node = token;
	if (node == NULL)
		return (NULL);
	while (node->prev != NULL)
	{
		node = node->prev;
	}
	return (node);
}
