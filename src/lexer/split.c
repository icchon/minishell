/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:32:54 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/14 21:25:47 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

static int	count_words_for_lexer(const char **quatesafe, const char *set)
{
	int	total_len;
	int	i;

	total_len = 0;
	i = -1;
	while (quatesafe[++i])
		total_len += count_words_withsep(quatesafe[i], set);
	return (total_len);
}

static char	**create_out(char **quatesafe, const char *set)
{
	int		i;
	int		k;
	int		j;
	char	**tmp;
	char	**out;

	out = (char **)malloc(sizeof(char *)
			* (count_words_for_lexer((const char **)quatesafe, set) + 1));
	i = 0;
	k = 0;
	while (quatesafe[i])
	{
		tmp = split_withsep(quatesafe[i], set);
		restore_ascii(tmp);
		j = 0;
		while (tmp[j])
			out[k++] = ft_strdup(tmp[j++]);
		ft_2darraydel(tmp);
		i++;
	}
	ft_2darraydel(quatesafe);
	out[k] = NULL;
	return (out);
}

char	**split_for_lexer(const char *str, const char *set)
{
	char	**quatesafe;

	quatesafe = split_quatesafe(str, set, 1);
	return (create_out(quatesafe, set));
}
