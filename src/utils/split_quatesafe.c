/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_quatesafe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:01:32 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/13 15:01:34 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void	keep_ascii(char *str, const char *set)
{
	int	status[ASCII_SIZE];
	int	i;

	if (!str)
		return ;
	init_quate_status(status);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '"')
			if (status[(int)str[i]] || status[NORMAL])
				update_quate_status(status, (t_quate_status)str[i]);
		if ((ft_contain(set, str[i]) || str[i] == ' ') && !status[NORMAL])
			str[i] *= -1;
		i++;
	}
}

void	restore_ascii(char **strs)
{
	int	i;
	int	j;

	i = 0;
	while (strs[i])
	{
		j = 0;
		while (strs[i][j])
		{
			if (strs[i][j] < 0)
			{
				strs[i][j] *= -1;
			}
			j++;
		}
		i++;
	}
	return ;
}

void	restore2d_ascii(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 0)
			str[i] *= -1;
		i++;
	}
	return ;
}

char	**split_quatesafe(const char *str, const char *set, int broken)
{
	char	*cp;
	int		status[ASCII_SIZE];
	char	**out;

	if (!str)
		return (NULL);
	cp = ft_strdup(str);
	init_quate_status(status);
	keep_ascii(cp, set);
	out = split_set(cp, " \t");
	if (!broken)
		restore_ascii(out);
	free(cp);
	return (out);
}
