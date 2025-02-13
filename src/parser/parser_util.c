/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:22:16 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/13 15:28:37 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

void	handle_token(t_astnode *node, t_token **token)
{
	t_token	*to_delete;
	t_token	*to_add;

	if (!ft_ismatch((*token)->type, 2, TK_WORD, TK_VAR))
	{
		to_delete = (*token);
		(*token) = (*token)->next;
		cut_token(token, to_delete);
		to_add = (*token);
		(*token) = (*token)->next;
		addback_token(&node->redirects, to_add);
		return ;
	}
	to_add = (*token);
	(*token) = (*token)->next;
	node->type = ASTND_CMD;
	addback_token(&node->args, to_add);
}

void	create_node_prop(t_astnode *node, t_token **token)
{
	while (*token && ft_ismatch((*token)->type, 6, TK_WORD, TK_VAR, TK_REDIN,
			TK_HEREDOC, TK_REDOUT, TK_REDOUT_APP))
	{
		handle_token(node, token);
	}
}
