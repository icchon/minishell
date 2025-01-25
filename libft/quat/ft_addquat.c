/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addquat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 09:49:11 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/31 11:10:33 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_quat.h"

t_quat	ft_add_quat(t_quat p, t_quat q)
{
	t_quat	res;

	res.r = p.r + q.r;
	res.i = p.i + q.i;
	res.j = p.j + q.j;
	res.k = p.k + q.k;
	return (res);
}
