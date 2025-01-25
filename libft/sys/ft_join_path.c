/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:57:01 by kaisobe           #+#    #+#             */
/*   Updated: 2025/01/04 07:49:09 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sys.h"

char	*ft_join_path(char *lower, char *upper)
{
	char	*res;
	char	*tmp;

	tmp = ft_strjoin(lower, "/");
	if (tmp == NULL)
		return (NULL);
	res = ft_strjoin(tmp, upper);
	free(tmp);
	return (res);
}
