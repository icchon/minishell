/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_token_util3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:20:16 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/12 07:27:35 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

void	addback_tokens(t_token **token, t_token *new)
{
	t_token	*last_node;

	if (!new)
		return ;
	last_node = last_token(*token);
	new->prev = last_node;
	if (last_node == NULL)
	{
		*token = new;
		return ;
	}
	last_node->next = new;
	return ;
}

void	insert_token(t_token **dst, t_token *src)
{
	t_token	*last;
	t_token	*next;

	if (*dst)
	{
		*dst = src;
		return ;
	}
	next = (*dst)->next;
	(*dst)->next = src;
	if (src)
	{
		src->prev = (*dst);
	}
	last = last_token(src);
	if (last)
	{
		last->next = next;
	}
	if (next)
	{
		next->prev = last;
	}
	return ;
}

void	print_token(t_token *token)
{
	int	type;

	if (!token)
		return ;
	printf("data : %s\n", token->data);
	type = (int)token->type;
	if (type == TK_WORD)
		printf("type : TK_WORD\n");
	else if (type == TK_PIPE)
		printf("type : TK_PIPE\n");
	else if (type == TK_HERE_DOC)
		printf("type : TK_HERE_DOC\n");
	else if (type == TK_OR)
		printf("type : TK_OR\n");
	else if (type == TK_AND)
		printf("type : TK_AND\n");
	else if (type == TK_LIMITER)
		printf("type : TK_LIMITER\n");
	else if (type == TK_INPUT_FILE)
		printf("type : TK_INPUT_FILE\n");
	else if (type == TK_OUTPUT_FILE)
		printf("type : TK_OUTPUT_FILE\n");
	else if (type == TK_OUTPUT_FILE_APPEND)
		printf("type : TK_OUTPUT_FILE_APPEND\n");
	else if (type == TK_REDIRECT_OUT)
		printf("type : TK_REDIRECT_OUT\n");
	else if (type == TK_REDIRECT_OUT_APPEND)
		printf("type : TK_REDIRECT_OUT_APPEND\n");
	else if (type == TK_REDIRECT_IN)
		printf("type : TK_REDIRECT_IN\n");
	else if (type == TK_UNDEFINED)
		printf("type == TK_UNDEFINED\n");
	else if (type == TK_VALIABLE)
		printf("type == TK_VALIABLE\n");
}

void	print_tokens(t_token *token)
{
	t_token	*node;

	node = token;
	if (!node)
		printf("null");
	while (node)
	{
		print_token(node);
		node = node->next;
	}
	return ;
}
