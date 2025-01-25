/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 23:57:12 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/22 14:39:18 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*create_p(uintptr_t p, t_options *ops)
{
	const char	*prefix = "0x";
	const char	*msg = "(nil)";
	char		*out;
	int			length;
	char		*hex;

	(void)ops;
	if (p == 0)
		return (ft_strdup((char *)msg));
	length = ft_get_digit_cnt(p, 16) + ft_strlen(prefix);
	out = ft_calloc((length + 1), sizeof(char));
	if (out == NULL)
		return (NULL);
	ft_memmove(out, prefix, ft_strlen(prefix));
	hex = ft_itoshex(p);
	if (hex == NULL)
		return (NULL);
	ft_memmove(&out[ft_strlen(prefix)], hex, ft_strlen(hex));
	ft_strlcat(out, hex, length);
	free(hex);
	return (out);
}

char	*create_p_arg_handler(va_list ap, t_options *ops)
{
	return (create_p((uintptr_t)va_arg(ap, void *), ops));
}
