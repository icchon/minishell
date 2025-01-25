/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 17:03:33 by icchon            #+#    #+#             */
/*   Updated: 2024/12/22 14:24:24 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (dest_len >= size)
	{
		return (size + src_len);
	}
	i = 0;
	while (i < size - dest_len - 1 && src[i])
	{
		dest[i + dest_len] = src[i];
		i++;
	}
	dest[i + dest_len] = '\0';
	return (dest_len + src_len);
}

// int	main(void)
// {
// 	char dest[30];
// 	memset(dest, 0, 30);
// 	char *src = (char *)"AAAAAAAAA";
// 	dest[0] = 'B';

// 	dest[0] = 'B';
// 	printf("res : %ld\n", ft_strlcat(dest, src, 1));
// 	printf("%s\n", dest);
// 	printf("cmp : %d\n", strcmp(dest, "B"));
// 	return (1);
// }