/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quat.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 09:42:15 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/31 11:22:56 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_QUAT_H
# define FT_QUAT_H

# include "ft_vec.h"
# include "math.h"

typedef struct s_quat
{
	double	r;
	double	i;
	double	j;
	double	k;
}			t_quat;

t_quat		ft_add_quat(t_quat p, t_quat q);
t_quat		ft_conjugate_quat(t_quat q);
t_quat		ft_inv_quat(t_quat q);
t_quat		ft_mul_quat(t_quat p, t_quat q);
t_quat		ft_new_quat(double r, double i, double j, double k);
t_quat		ft_normalize_quat(t_quat q);
t_vector3	ft_quat_to_vec3(t_quat q);
t_quat		ft_rotation_quat(t_vector3 v, double phase);
t_quat		ft_scale_quat(t_quat q, double a);
t_quat		ft_vec3_to_quat(t_vector3 v);
t_vector3	ft_rotate_vec3(t_vector3 x, t_vector3 v, double phase);
#endif