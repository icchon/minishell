/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:36:58 by kaisobe           #+#    #+#             */
/*   Updated: 2025/01/01 19:37:57 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_is.h"
#include "ft_str.h"

static int	indexof(char *str, char target)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == target)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int			i;
	int			sign;
	long long	res;
	int			n_base;

	n_base = (int)ft_strlen(base);
	i = 0;
	sign = 1;
	res = 0;
	while (ft_isspace(str[i]))
		i++;
	if (ft_issign(str[i]))
		if (str[i++] == '-')
			sign *= -1;
	while (str[i])
	{
		res = res * n_base + sign * (indexof(base, str[i++]));
		if (res >= LONG_MAX || res <= LONG_MIN)
		{
			break ;
		}
	}
	return ((int)res);
}
