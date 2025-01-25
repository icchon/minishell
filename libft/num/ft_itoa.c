/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 07:43:11 by icchon            #+#    #+#             */
/*   Updated: 2024/12/22 14:19:58 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_num.h"

static int	ft_get_digit(unsigned long long n)
{
	int	digit_cnt;

	digit_cnt = 1;
	while (n >= 10)
	{
		digit_cnt++;
		n /= 10;
	}
	return (digit_cnt);
}

char	*ft_itoa(int n)
{
	int			is_sign;
	long long	buff;
	char		*res;
	int			i;

	is_sign = (n < 0);
	buff = (long long)n;
	if (is_sign)
		buff *= -1;
	res = (char *)malloc(sizeof(char) * (ft_get_digit(buff) + is_sign + 1));
	if (res == NULL)
		return (NULL);
	i = ft_get_digit(buff) + is_sign;
	res[i] = '\0';
	res[0] = '-';
	i--;
	while (i >= is_sign)
	{
		res[i] = (buff % 10) + '0';
		buff /= 10;
		i--;
	}
	return (res);
}
