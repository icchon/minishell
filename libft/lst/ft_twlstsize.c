/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_twlstsize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:00:12 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/24 00:24:30 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"

int	ft_twlstsize(t_twlist *lst)
{
	int			cnt;
	t_twlist	*node;

	cnt = 0;
	node = ft_twlsthead(lst);
	while (node != NULL)
	{
		node = node->next;
		cnt++;
	}
	return (cnt);
}
