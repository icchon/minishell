/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scalequat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 09:49:57 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/31 11:10:54 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_quat.h"

t_quat	ft_scale_quat(t_quat q, double a)
{
	t_quat	res;

	res.r = q.r * a;
	res.i = q.i * a;
	res.j = q.j * a;
	res.k = q.k * a;
	return (res);
}
