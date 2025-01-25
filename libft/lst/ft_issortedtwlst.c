/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issortedtwlst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 00:06:58 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/24 00:34:06 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"

int	ft_issortedtwlst(t_twlist *lst, int reversed)
{
	t_twlist	*node;
	t_twlist	*next;
	int			node_val;
	int			next_val;

	node = lst;
	while (node != NULL)
	{
		next = node->next;
		if (next == NULL)
			break ;
		node_val = *(int *)node->content;
		next_val = *(int *)next->content;
		if ((!reversed && (node_val > next_val)) || (reversed
				&& (node_val < next_val)))
			return (0);
		node = next;
	}
	return (1);
}
