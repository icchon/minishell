/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itolhex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:04:21 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/22 14:54:10 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_num.h"

static void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*res;
	size_t	total_size;
	char	*byte_ptr;
	size_t	i;

	total_size = nmemb * size;
	if (nmemb == 0 || size == 0)
	{
		res = (char *)malloc(1 * sizeof(char));
		res[0] = '\0';
		return (res);
	}
	if (nmemb > __SIZE_MAX__ / size)
		return (NULL);
	res = malloc(total_size);
	if (res == NULL)
		return (NULL);
	byte_ptr = (char *)res;
	i = 0;
	while (i < total_size)
		byte_ptr[i++] = 0;
	return (res);
}

char	*ft_itolhex(uintptr_t n)
{
	char		*res;
	int			i;
	const char	*hex_elems = "0123456789ABCDEF";
	int			length;

	length = ft_get_digit_cnt(n, 16);
	res = (char *)ft_calloc((length + 1), sizeof(char));
	if (res == NULL)
		return (NULL);
	i = length - 1;
	while (i >= 0)
	{
		res[i] = hex_elems[(n % 16)];
		n /= 16;
		i--;
	}
	return (res);
}
