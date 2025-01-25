/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_twlstadd_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 11:57:38 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/23 14:25:21 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"
#include <stdio.h>

void	ft_twlstadd_back(t_twlist **lst, t_twlist *new)
{
	t_twlist	*last_node;

	last_node = ft_twlstlast(*lst);
	if (last_node == NULL)
	{
		*lst = new;
		return ;
	}
	new->prev = last_node;
	new->next = NULL;
	last_node->next = new;
	return ;
}
