/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_random_file.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 07:38:02 by kaisobe           #+#    #+#             */
/*   Updated: 2025/01/13 20:56:27 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sys.h"

char	*ft_create_random_file(char *extension)
{
	char		*out;
	char		*tmp;
	u_int32_t	rand;
	int			fd;

	rand = ft_rand_u32(ft_generate_seed());
	tmp = ft_utoa(rand);
	if (!tmp)
		return (NULL);
	if (extension)
		out = ft_strjoin_safe(tmp, extension, 1, 0);
	else
		out = ft_strdup(tmp);
	if (ft_path_exist(out))
	{
		free(out);
		return (ft_create_random_file(extension));
	}
	fd = ft_create_file(out);
	if (fd == -1)
		return (NULL);
	close(fd);
	return (out);
}
