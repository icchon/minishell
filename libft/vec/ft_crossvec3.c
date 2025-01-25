/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crossvec3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 12:34:17 by kaisobe           #+#    #+#             */
/*   Updated: 2025/01/01 12:36:38 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vec.h"

t_vector3	ft_cross_vec3(t_vector3 p, t_vector3 q)
{
	t_vector3	res;

	res.x = p.y * q.z - p.z - q.y;
	res.y = p.z * q.x - p.x * q.z;
	res.z = p.x * q.y - p.y * q.x;
	return (res);
}
