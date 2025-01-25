/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:32:25 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/22 14:54:25 by kaisobe          ###   ########.fr       */
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

char	*ft_utoa(unsigned int n)
{
	char	*res;
	int		i;
	int		length;

	length = ft_get_digit_cnt(n, 10);
	res = (char *)ft_calloc(length + 1, sizeof(char));
	if (res == NULL)
		return (NULL);
	i = length - 1;
	while (i >= 0)
	{
		res[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	return (res);
}
