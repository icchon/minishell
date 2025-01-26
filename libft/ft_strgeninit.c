/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strgeninit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:57:06 by tkitago           #+#    #+#             */
/*   Updated: 2025/01/24 18:49:27 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_strgen	*ft_strgeninit(void)
{
	t_strgen	*strgen;

	strgen = (t_strgen *)malloc(sizeof(t_strgen));
	if (!strgen)
		return (NULL);
	strgen->str = NULL;
	strgen->position = 0;
	strgen->error = 0;
	return (strgen);
}
