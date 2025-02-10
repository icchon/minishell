/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 06:08:59 by icchon            #+#    #+#             */
/*   Updated: 2025/02/10 15:33:19 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	char	*line;
	int		bytes_read;
	char	c;
	int		i;

	bytes_read = read(fd, &c, 1);
	if (bytes_read <= 0)
		return (NULL);
	line = (char *)ft_calloc(GNL_BUFFSIZE, sizeof(char));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (1)
	{
		if (bytes_read <= 0 || c == '\n')
			return (line);
		line[i] = c;
		i++;
		bytes_read = read(fd, &c, 1);
	}
	return (NULL);
}
