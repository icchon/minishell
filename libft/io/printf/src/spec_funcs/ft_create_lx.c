/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_lx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 23:59:32 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/22 14:39:11 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*create_lx(unsigned int lx, t_options *ops)
{
	return (ft_precisely_itolhex(lx, ops->prec));
}

char	*create_lx_arg_handler(va_list ap, t_options *ops)
{
	return (create_lx((unsigned int)va_arg(ap, unsigned int), ops));
}
