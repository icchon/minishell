/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalizequat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 09:50:15 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/31 11:11:15 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_quat.h"

t_quat	ft_normalize_quat(t_quat q)
{
	double	norm;

	norm = sqrt((q.r * q.r) + (q.i * q.i) + (q.j * q.j) + (q.k * q.k));
	return (ft_scale_quat(q, 1 / norm));
}
