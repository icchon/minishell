/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 23:56:23 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/22 14:39:26 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*create_s(char *s, t_options *ops)
{
	const char	*msg = "(null)";

	(void)ops;
	if (s == NULL)
	{
		if (!(ops->prec == -1 || ops->prec >= (int)ft_strlen(msg)))
		{
			ops->prec = 0;
		}
		return (ft_strdup((char *)msg));
	}
	return (ft_strdup(s));
}

char	*create_s_arg_handler(va_list ap, t_options *ops)
{
	return (create_s((char *)va_arg(ap, char *), ops));
}
