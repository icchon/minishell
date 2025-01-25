/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 15:51:23 by icchon            #+#    #+#             */
/*   Updated: 2024/12/22 14:12:41 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dest_ptr;
	const char	*src_ptr;

	dest_ptr = (char *)dest;
	src_ptr = (const char *)src;
	if (dest <= src)
	{
		while (n > 0)
		{
			*dest_ptr++ = *src_ptr++;
			n--;
		}
	}
	else
	{
		dest_ptr += n - 1;
		src_ptr += n - 1;
		while (n > 0)
		{
			*dest_ptr-- = *src_ptr--;
			n--;
		}
	}
	return (dest);
}
