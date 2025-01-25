/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quattovec3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 09:52:45 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/31 11:11:12 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_quat.h"

t_vector3	ft_quat_to_vec3(t_quat q)
{
	return (ft_new_vec3(q.i, q.j, q.k));
}
