/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:20:00 by tkitago           #+#    #+#             */
/*   Updated: 2024/11/04 15:46:32 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*temp;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	temp = str;
	while (*s1)
		*temp++ = *s1++;
	while (*s2)
		*temp++ = *s2++;
	*temp = '\0';
	return (str);
}

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*str;
// 	size_t	i;
// 	size_t	j;

// 	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
// 	if (!str)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	while (s1[i] != '\0')
// 	{
// 		str[j] = s1[i];
// 		j++;
// 		i++;
// 	}
// 	i = 0;
// 	while (s2[i] != '\0')
// 	{
// 		str[j] = s2[i];
// 		j++;
// 		i++;
// 	}
// 	str[j] = '\0';
// 	return (str);
// }
