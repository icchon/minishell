#include "minishell.h"

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
