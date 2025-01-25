/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 09:42:45 by kaisobe           #+#    #+#             */
/*   Updated: 2025/01/01 12:37:09 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VEC_H
# define FT_VEC_H

# include "math.h"

typedef struct s_vector3
{
	double	x;
	double	y;
	double	z;
}			t_vector3;

typedef struct s_vector2
{
	double	x;
	double	y;
}			t_vector2;

t_vector3	ft_add_vec3(t_vector3 v1, t_vector3 v2);
t_vector3	ft_mul_vec3(t_vector3 v1, t_vector3 v2);
t_vector3	ft_new_vec3(double x, double y, double z);
t_vector3	ft_normalize_vec3(t_vector3 v);
t_vector3	ft_scalar_vec3(t_vector3 v, double a);
t_vector3	ft_sub_vec3(t_vector3 v1, t_vector3 v2);
t_vector3	ft_cross_vec3(t_vector3 p, t_vector3 q);
double		ft_norm_vec3(t_vector3 v);

t_vector2	ft_add_vec2(t_vector2 v1, t_vector2 v2);
t_vector2	ft_mul_vec2(t_vector2 v1, t_vector2 v2);
t_vector2	ft_new_vec2(double x, double y);
t_vector2	ft_normalize_vec2(t_vector2 v);
t_vector2	ft_scalar_vec2(t_vector2 v, double a);
t_vector2	ft_sub_vec2(t_vector2 v1, t_vector2 v2);
double		ft_norm_vec2(t_vector2 v);

#endif