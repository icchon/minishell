/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mulquat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 09:48:50 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/31 11:10:40 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_quat.h"

t_quat	ft_mul_quat(t_quat p, t_quat q)
{
	t_quat	res;

	res.r = (p.r * q.r) - (p.i * q.i) - (p.j * q.j) - (p.k * q.k);
	res.i = (p.r * q.i) + (p.i * q.r) + (p.j * q.k) - (p.k * q.j);
	res.j = (p.r * q.j) - (p.i * q.k) + (p.j * q.r) + (p.k * q.i);
	res.k = (p.r * q.k) + (p.i * q.j) - (p.j * q.i) + (p.k * q.r);
	return (res);
}
