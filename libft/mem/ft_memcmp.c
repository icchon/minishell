/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 16:15:20 by icchon            #+#    #+#             */
/*   Updated: 2024/12/22 14:12:15 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	const char	*ptr1;
	const char	*ptr2;

	if (n == 0)
		return (0);
	ptr1 = (const char *)s1;
	ptr2 = (const char *)s2;
	i = 0;
	while (ptr1[i] == ptr2[i] && i < n - 1)
	{
		i++;
	}
	return ((unsigned char)ptr1[i] - (unsigned char)ptr2[i]);
}
