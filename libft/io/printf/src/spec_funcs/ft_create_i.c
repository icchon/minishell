/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 23:58:08 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/22 14:39:06 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*create_i(int i, t_options *ops)
{
	(void)ops;
	return (ft_precisely_itoa(i, ops->prec));
}

char	*create_i_arg_handler(va_list ap, t_options *ops)
{
	return (create_i((int)va_arg(ap, int), ops));
}
