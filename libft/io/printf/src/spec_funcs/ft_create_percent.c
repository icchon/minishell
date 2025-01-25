/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 10:57:06 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/22 14:39:22 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*create_percent(void)
{
	return (ft_strdup("%"));
}

char	*create_percent_arg_handler(va_list ap, t_options *ops)
{
	(void)ap;
	(void)ops;
	return (create_percent());
}
