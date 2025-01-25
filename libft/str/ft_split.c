/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 07:24:58 by icchon            #+#    #+#             */
/*   Updated: 2025/01/24 09:23:58 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

static int	ft_count_words(char const *s, char c)
{
	int	cnt;
	int	is_head;
	int	i;

	cnt = 0;
	is_head = 1;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			is_head = 1;
		}
		else
		{
			if (is_head)
			{
				cnt++;
			}
			is_head = 0;
		}
		i++;
	}
	return (cnt);
}

static int	ft_get_kth_start_idx(char const *s, char c, int k)
{
	int	i;
	int	cnt;
	int	is_head;

	is_head = 1;
	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] == c)
			is_head = 1;
		else
		{
			if (is_head)
			{
				cnt++;
				if (cnt == k)
					return (i);
			}
			is_head = 0;
		}
		i++;
	}
	return (-1);
}

static int	ft_get_kth_word_len(char const *s, char c, int k)
{
	int	start_idx;
	int	i;

	start_idx = ft_get_kth_start_idx(s, c, k);
	i = 0;
	while (s[start_idx + i] != c && s[start_idx + i])
	{
		i++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;

	res = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < ft_count_words(s, c))
	{
		res[i] = (char *)malloc(sizeof(char) * (ft_get_kth_word_len(s, c, (i
							+ 1)) + 1));
		if (res[i] == NULL)
		{
			free_strs(res);
			return (NULL);
		}
		j = -1;
		while (++j < ft_get_kth_word_len(s, c, (i + 1)))
			res[i][j] = s[ft_get_kth_start_idx(s, c, (i + 1)) + j];
		res[i++][j] = '\0';
	}
	res[i] = NULL;
	return (res);
}
