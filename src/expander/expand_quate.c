/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_quate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:36:15 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/15 08:34:51 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

static char	*process_in_normal_status(int *status, char *word, int *i)
{
	int		offset;
	char	*data;
	char	*tmp;

	offset = ft_calc_next_str(&word[*i], "'\"");
	tmp = ft_substr(&word[*i], 0, offset);
	*i += offset;
	data = replace_env_vars(tmp);
	free(tmp);
	update_quate_status(status, word[*i]);
	return (data);
}

static char	*process_in_quate(int *status, char *word, int *i)
{
	int		offset;
	char	*data;
	char	*tmp;

	offset = ft_calc_next_chr(&word[*i + 1], word[*i]);
	(*i)++;
	data = ft_substr(&word[*i], 0, offset);
	if (status[IN_DOUBLE_QUOT])
	{
		tmp = data;
		data = replace_env_vars(data);
		free(tmp);
	}
	update_quate_status(status, (t_quate_status)word[*i + offset]);
	*i += (offset + 1);
	return (data);
}

char	*expand_word(char *word)
{
	int		status[ASCII_SIZE];
	int		i;
	char	*data;
	char	*out;

	init_quate_status(status);
	out = NULL;
	i = 0;
	while (word[i])
	{
		if (status[NORMAL])
		{
			data = process_in_normal_status(status, word, &i);
		}
		else
		{
			data = process_in_quate(status, word, &i);
		}
		out = ft_strjoin_safe(out, data, 1, 1);
	}
	return (out);
}
