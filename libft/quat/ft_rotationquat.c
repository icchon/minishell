/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotationquat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 09:41:45 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/31 11:11:06 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_quat.h"

t_quat	ft_rotation_quat(t_vector3 v, double phase)
{
	t_quat	res;

	v = ft_normalize_vec3(v);
	res.r = cos(phase / 2);
	res.i = v.x * sin(phase / 2);
	res.j = v.y * sin(phase / 2);
	res.k = v.z * sin(phase / 2);
	return (res);
}
