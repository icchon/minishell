/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:23:25 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/10 15:23:26 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

int	contain_backslash(char *str)
{
	if (ft_strchr(str, '/'))
		return (1);
	return (0);
}

int	is_executable(char *path)
{
	int	res;

	res = access(path, X_OK);
	return (res == 0);
}

int	is_directory(char *path)
{
	static t_stat	st = {0};

	stat(path, &st);
	return ((st.st_mode & S_IFMT) == S_IFDIR);
}
