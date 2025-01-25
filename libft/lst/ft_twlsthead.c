/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_twlsthead.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:04:21 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/24 03:10:39 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"
#include <stdio.h>

t_twlist	*ft_twlsthead(t_twlist *lst)
{
	t_twlist	*node;

	node = lst;
	if (node == NULL)
		return (NULL);
	while (node->prev != NULL)
	{
		node = node->prev;
	}
	return (node);
}
