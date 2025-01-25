/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precisely_itolhex.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:57:22 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/22 14:53:36 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_num.h"

static int	ft_max(int argn, ...)
{
	va_list	ap;
	int		maximum;
	int		tmp;
	int		i;

	i = 0;
	va_start(ap, argn);
	maximum = INT_MIN;
	while (i < argn)
	{
		tmp = va_arg(ap, int);
		if (tmp > maximum)
		{
			maximum = tmp;
		}
		i++;
	}
	va_end(ap);
	return (maximum);
}

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

static void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = (char *)s;
	while (i < n)
	{
		ptr[i] = (char)c;
		i++;
	}
	return (s);
}

char	*ft_precisely_itolhex(uintptr_t n, int precision)
{
	char		*res;
	int			i;
	const char	*hex_elems = "0123456789ABCDEF";
	int			length;
	int			zero_cnt;

	zero_cnt = ft_max(2, 0, (precision - ft_get_digit_cnt(n, 16)));
	length = ft_get_digit_cnt(n, 16) + zero_cnt;
	res = (char *)ft_calloc((length + 1), sizeof(char));
	if (res == NULL)
		return (NULL);
	i = length - 1;
	ft_memset(res, '0', length);
	while (i >= 0)
	{
		res[i] = hex_elems[(n % 16)];
		n /= 16;
		i--;
	}
	return (res);
}
