/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exfree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 18:51:05 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/23 22:43:07 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_util.h"

void	ft_exfree(int argn, ...)
{
	va_list	ap;
	int		i;

	i = 0;
	va_start(ap, argn);
	while (i < argn)
	{
		free(va_arg(ap, void *));
		i++;
	}
	va_end(ap);
	return ;
}
