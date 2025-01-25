/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_chain.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:57:38 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/22 15:01:42 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

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

char	*ft_create_chain(char c, int n)
{
	char	*out;

	out = (char *)ft_calloc(n + 1, sizeof(char));
	ft_memset(out, c, n);
	return (out);
}
