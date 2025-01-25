/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_nothing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 07:36:13 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/22 14:39:14 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*create_nothing(void)
{
	return (ft_strdup(""));
}

char	*create_nothing_arg_handler(va_list ap, t_options *ops)
{
	(void)ap;
	(void)ops;
	return (create_nothing());
}
