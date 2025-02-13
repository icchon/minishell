/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:01:25 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/13 15:01:26 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

static int	count_words(char const *s, const char *set)
{
	int	cnt;
	int	is_head;
	int	i;

	cnt = 0;
	is_head = 1;
	i = 0;
	while (s[i])
	{
		if (ft_contain(set, s[i]))
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

static int	get_kth_idx(char const *s, const char *set, int k)
{
	int	i;
	int	cnt;
	int	is_head;

	is_head = 1;
	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (ft_contain(set, s[i]))
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

static int	get_kth_len(char const *s, const char *set, int k)
{
	int	start_idx;
	int	i;

	start_idx = get_kth_idx(s, set, k);
	i = 0;
	while (!ft_contain(set, s[start_idx + i]) && s[start_idx + i])
	{
		i++;
	}
	return (i);
}

char	**split_set(char const *s, const char *set)
{
	char	**res;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (count_words(s, set) + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < count_words(s, set))
	{
		res[i] = (char *)malloc(sizeof(char) * (get_kth_len(s, set, (i + 1))
					+ 1));
		j = -1;
		while (++j < get_kth_len(s, set, (i + 1)))
			res[i][j] = s[get_kth_idx(s, set, (i + 1)) + j];
		res[i++][j] = '\0';
	}
	res[i] = NULL;
	return (res);
}
