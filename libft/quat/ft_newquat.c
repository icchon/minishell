/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newquat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 09:51:12 by kaisobe           #+#    #+#             */
/*   Updated: 2025/01/01 19:38:50 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_quat.h"

t_quat	ft_new_quat(double r, double i, double j, double k)
{
	t_quat	q;

	q.r = r;
	q.i = i;
	q.j = j;
	q.k = k;
	return (q);
}
