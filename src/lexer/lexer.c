/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:20:08 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/13 15:57:13 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

t_token	*lexer(char *line)
{
	t_token	*head;
	char	**splited;
	int		i;

	head = NULL;
	splited = split_for_lexer(line, META);
	i = 0;
	while (1)
	{
		if (!splited[i])
			break ;
		if (ft_isequal(splited[i], "|") && ft_isequal(splited[i + 1], "|"))
			addback_token((i++, &head), new_token(TK_UNDEFINED, "||"));
		else if (ft_isequal(splited[i], "&") && ft_isequal(splited[i + 1], "&"))
			addback_token((i++, &head), new_token(TK_UNDEFINED, "&&"));
		else if (ft_isequal(splited[i], "<") && ft_isequal(splited[i + 1], "<"))
			addback_token((i++, &head), new_token(TK_UNDEFINED, "<<"));
		else if (ft_isequal(splited[i], ">") && ft_isequal(splited[i + 1], ">"))
			addback_token((i++, &head), new_token(TK_UNDEFINED, ">>"));
		else
			addback_token((&head), new_token(TK_UNDEFINED, splited[i]));
		i++;
	}
	tokenizer(head);
	return (ft_2darraydel(splited), head);
}
