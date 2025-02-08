/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim_safe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 20:25:35 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/08 20:28:38 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim_safe(char *s1, char *set)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = NULL;
	if (!((ft_strlen(s1) > 0) || (ft_strlen(set) > 0)))
	{
		str = ft_strdup(s1);
		free(s1);
		return (str);
	}
	if (s1 != NULL && set != NULL)
	{
		i = 0;
		j = ft_strlen(s1);
		while (s1[i] && ft_strchr(set, s1[i]))
			i++;
		while (s1[j - 1] && ft_strchr(set, s1[j - 1]) && j > i)
			j--;
		str = (char *)xmalloc(sizeof(char) * (j - i + 1));
		if (str)
			ft_strlcpy(str, &s1[i], j - i + 1);
	}
	free(s1);
	return (str);
}
