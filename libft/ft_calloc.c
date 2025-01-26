/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:27:18 by tkitago           #+#    #+#             */
/*   Updated: 2024/10/31 13:49:29 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	byte;
	void	*mem;

	if (!nmemb || !size)
	{
		return (malloc(0));
	}
	if (nmemb > SIZE_MAX / size)
	{
		return (NULL);
	}
	byte = nmemb * size;
	mem = malloc(byte);
	if (mem == NULL)
		return (NULL);
	ft_bzero(mem, byte);
	return (mem);
}
