/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bufferionew.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:54:52 by tkitago           #+#    #+#             */
/*   Updated: 2025/01/24 18:50:01 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bufferio	*ft_bufferionew(int fd, int close_on_error)
{
	t_bufferio	*ret;

	if (fd == -1)
		return (NULL);
	ret = (t_bufferio *)malloc(sizeof(t_bufferio));
	if (!ret)
	{
		if (close_on_error)
			close(fd);
		return (NULL);
	}
	ret->strgen = ft_strgeninit();
	if (!ret->strgen)
	{
		free(ret);
		if (close_on_error)
			close(fd);
		return (NULL);
	}
	ret->fd = fd;
	return (ret);
}
// init bufferio and set fd and resource