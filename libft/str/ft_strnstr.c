/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 17:49:26 by icchon            #+#    #+#             */
/*   Updated: 2025/01/03 14:02:57 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	haystack_len;
	size_t	needle_len;
	size_t	i;

	if (len == 0)
	{
		if (needle[0] == '\0')
			return ((char *)haystack);
		return (NULL);
	}
	haystack_len = ft_strlen(haystack);
	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return ((char *)haystack);
	i = 0;
	while (i + needle_len <= (size_t)ft_min(2, haystack_len, len) && i < len)
	{
		if (ft_strncmp(haystack + i, needle, needle_len) == 0)
		{
			return ((char *)(haystack + i));
		}
		i++;
	}
	return (NULL);
}
