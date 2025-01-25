/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 23:57:46 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/22 14:39:03 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*create_d(int d, t_options *ops)
{
	return (ft_precisely_itoa(d, ops->prec));
}

char	*create_d_arg_handler(va_list ap, t_options *ops)
{
	return (create_d((int)va_arg(ap, int), ops));
}
