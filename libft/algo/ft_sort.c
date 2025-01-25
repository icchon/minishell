/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:41:03 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/23 23:42:29 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_algo.h"

static void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dest_ptr;
	const char	*src_ptr;

	dest_ptr = (char *)dest;
	src_ptr = (const char *)src;
	i = 0;
	while (i < n)
	{
		dest_ptr[i] = src_ptr[i];
		i++;
	}
	return (dest);
}

static int	ft_swap(void *a, void *b, size_t n)
{
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * n);
	if (tmp == NULL)
	{
		return (0);
	}
	ft_memcpy(tmp, a, n);
	ft_memcpy(a, b, n);
	ft_memcpy(b, tmp, n);
	free(tmp);
	return (1);
}

void	ft_sort(int *arr, int n, int reversed)
{
	int	i;
	int	sign;

	i = 0;
	sign = ft_quadratic_transform(0, -2, 1, reversed);
	while (i < n - 1)
	{
		if (sign * arr[i] > sign * arr[i + 1])
		{
			ft_swap(&arr[i], &arr[i + 1], sizeof(int));
			i = 0;
			continue ;
		}
		i++;
	}
	return ;
}
