/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newvec3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 09:46:00 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/31 11:10:13 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vec.h"

t_vector3	ft_new_vec3(double x, double y, double z)
{
	t_vector3	pos;

	pos.x = x;
	pos.y = y;
	pos.z = z;
	return (pos);
}
