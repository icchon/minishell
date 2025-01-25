/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conjugate_quat.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 09:49:33 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/31 11:10:35 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_quat.h"

t_quat	ft_conjugate_quat(t_quat q)
{
	t_quat	conjugate_q;

	conjugate_q.r = q.r;
	conjugate_q.i = -1 * q.i;
	conjugate_q.j = -1 * q.j;
	conjugate_q.k = -1 * q.k;
	return (conjugate_q);
}
