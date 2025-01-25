/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_twlstget.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icchon <icchon@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-27 07:02:47 by icchon            #+#    #+#             */
/*   Updated: 2024-12-27 07:02:47 by icchon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"

t_twlist	*ft_twlstget(t_twlist *lst, int index)
{
	t_twlist	*node;
	int			i;

	i = 0;
	if (index >= 0)
	{
		node = ft_twlsthead(lst);
		while (node)
		{
			if (i++ == index)
				return (node);
			node = node->next;
		}
		return (NULL);
	}
	i = -1;
	node = ft_twlstlast(lst);
	while (node)
	{
		if (i-- == index)
			return (node);
		node = node->prev;
	}
	return (NULL);
}
