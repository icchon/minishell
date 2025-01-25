/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalizevec3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 09:47:58 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/31 11:11:46 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vec.h"

t_vector3	ft_normalize_vec3(t_vector3 v)
{
	double	norm;

	norm = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	return (ft_scalar_vec3(v, 1 / norm));
}
