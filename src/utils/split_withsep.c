/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_withsep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:01:15 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/13 15:01:17 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

int	count_words_withsep(const char *str, const char *set)
{
	int	cnt;
	int	is_head;
	int	i;

	cnt = 0;
	is_head = 1;
	i = 0;
	while (str[i])
	{
		if (ft_contain(set, str[i]))
		{
			is_head = 1;
			cnt++;
		}
		else
		{
			if (is_head)
				cnt++;
			is_head = 0;
		}
		i++;
	}
	return (cnt);
}

static int	get_kth_idx_withsep(char const *s, const char *set, int k)
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
		{
			is_head = 1;
			cnt++;
		}
		else
		{
			if (is_head)
				cnt++;
			is_head = 0;
		}
		if (cnt == k)
			return (i);
		i++;
	}
	return (-1);
}

static int	get_kth_len_withsep(char const *s, const char *set, int k)
{
	int	start_idx;
	int	i;

	start_idx = get_kth_idx_withsep(s, set, k);
	i = 0;
	while (s[i])
	{
		if (ft_contain(set, s[i + start_idx]))
		{
			if (i == 0)
				return (1);
			break ;
		}
		i++;
	}
	return (i);
}

char	**split_withsep(const char *str, const char *set)
{
	char	**res;
	int		i;
	int		j;

	if (!str)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (count_words_withsep(str, set) + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < count_words_withsep(str, set))
	{
		res[i] = (char *)malloc(sizeof(char) * (get_kth_len_withsep(str, set, (i
							+ 1)) + 1));
		j = -1;
		while (++j < get_kth_len_withsep(str, set, (i + 1)))
			res[i][j] = str[get_kth_idx_withsep(str, set, (i + 1)) + j];
		res[i++][j] = '\0';
	}
	res[i] = NULL;
	return (res);
}
