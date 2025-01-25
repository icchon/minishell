/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 04:33:18 by icchon            #+#    #+#             */
/*   Updated: 2024/12/22 14:07:48 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"

int	ft_lstsize(t_list *lst)
{
	int		cnt;
	t_list	*node;

	cnt = 0;
	node = lst;
	if (node == NULL)
		return (cnt);
	while (node != NULL)
	{
		node = node->next;
		cnt++;
	}
	return (cnt);
}
