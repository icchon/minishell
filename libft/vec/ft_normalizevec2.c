/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalizevec2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 09:47:58 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/31 18:53:27 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vec.h"

t_vector2	ft_normalize_vec2(t_vector2 v)
{
	double	norm;

	norm = sqrt(v.x * v.x + v.y * v.y);
	return (ft_scalar_vec2(v, 1 / norm));
}
