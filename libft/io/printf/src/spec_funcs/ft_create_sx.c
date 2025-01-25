/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_sx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 23:59:13 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/22 14:39:30 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*create_sx(unsigned int x, t_options *ops)
{
	return (ft_precisely_itoshex(x, ops->prec));
}

char	*create_sx_arg_handler(va_list ap, t_options *ops)
{
	return (create_sx((unsigned int)va_arg(ap, unsigned int), ops));
}
