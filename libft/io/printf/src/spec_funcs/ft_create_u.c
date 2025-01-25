/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 23:58:35 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/22 14:39:35 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*create_u(unsigned int u, t_options *ops)
{
	return (ft_precisely_utoa(u, ops->prec));
}

char	*create_u_arg_handler(va_list ap, t_options *ops)
{
	return (create_u((unsigned int)va_arg(ap, unsigned int), ops));
}
