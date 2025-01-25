/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chr_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:40:17 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/22 16:27:58 by kaisobe          ###   ########.fr       */
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

char	*ft_chr_to_str(char c)
{
	char	*out;

	out = (char *)ft_calloc(2, sizeof(char));
	if (out == NULL)
		return (NULL);
	out[0] = c;
	return (out);
}
