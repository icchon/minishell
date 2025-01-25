/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_twlstlast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:03:16 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/23 12:58:20 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"
#include <stdio.h>

t_twlist	*ft_twlstlast(t_twlist *lst)
{
	t_twlist	*node;

	if (lst == NULL)
		return (lst);
	node = lst;
	if (node->next == NULL)
	{
	}
	while (node->next != NULL)
	{
		node = node->next;
	}
	return (node);
}
