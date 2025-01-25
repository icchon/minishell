/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 23:52:56 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/22 14:38:59 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*create_c(int c, t_options *ops)
{
	(void)ops;
	return (ft_chr_to_str(c));
}

char	*create_c_arg_handler(va_list ap, t_options *ops)
{
	return (create_c((int)va_arg(ap, int), ops));
}
