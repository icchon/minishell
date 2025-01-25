/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotatevec3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 09:53:18 by kaisobe           #+#    #+#             */
/*   Updated: 2025/01/01 17:12:12 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_quat.h"
#include <stdio.h>

t_vector3	ft_rotate_vec3(t_vector3 x, t_vector3 v, double phase)
{
	t_quat	p;
	t_quat	q;
	t_quat	inv_q;
	t_quat	rotated;

	q = ft_rotation_quat(v, phase);
	p = ft_vec3_to_quat(x);
	inv_q = ft_inv_quat(q);
	rotated = ft_mul_quat(ft_mul_quat(q, p), inv_q);
	return (ft_quat_to_vec3(rotated));
}
