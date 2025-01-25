/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_twlstclear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:05:59 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/23 12:08:28 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"

void	ft_twlstclear(t_twlist **lst, void (*del)(void *))
{
	t_twlist	*node;
	t_twlist	*next;

	node = ft_twlsthead(*lst);
	while (node != NULL)
	{
		del(node->content);
		next = node->next;
		free(node);
		node = next;
	}
	*lst = NULL;
	return ;
}
