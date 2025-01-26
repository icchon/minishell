/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:19:53 by tkitago           #+#    #+#             */
/*   Updated: 2024/11/04 15:41:29 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	char	*dest;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	dest = str;
	while (*s != '\0')
	{
		*dest++ = *s++;
	}
	*dest = '\0';
	return (str);
}

// char	*ft_strdup(const char *s)
// {
// 	char	*str;
// 	size_t	i;

// 	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
// 	if (!str)
// 		return (NULL);
// 	i = 0;
// 	while (s[i] != '\0')
// 	{
// 		str[i] = s[i];
// 		i++;
// 	}
// 	str[i] = '\0';
// 	return (str);
// }
