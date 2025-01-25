/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_twlstadd_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:08:42 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/24 04:22:50 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"

void	ft_twlstadd_front(t_twlist **lst, t_twlist *new)
{
	if (new == NULL)
		return ;
	new->next = *lst;
	new->prev = NULL;
	if (*lst != NULL)
		(*lst)->prev = new;
	*lst = new;
}
