/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_vars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:11:33 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/13 15:38:33 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

static void	process_doller(char *str, size_t *i, char **out)
{
	size_t	len;
	char	*key;

	if (str[*i] == '$')
	{
		len = ft_calc_next_str(&str[++(*i)], "\t\n\v\f\r $");
		key = ft_substr(&str[*i], 0, len);
		if (ft_isequal(key, "?"))
			*out = ft_strjoin_safe(*out, ft_itoa(grobal_status(GET)), 1, 1);
		else if (ft_strlen(key) <= 0)
			*out = ft_strjoin_safe(*out, "$", 1, 0);
		else
			*out = ft_strjoin_safe(*out, ft_get_env(key, grobal_env(GET)), 1,
					0);
		free(key);
		(*i) += len;
	}
}

t_token	*token_variable_split(t_token **token)
{
	char	*expanded;
	char	**splited;
	t_token	*new_tokens;
	t_token	*new;
	size_t	i;

	if (!(*token && (*token)->type == TK_VAR))
		return (NULL);
	expanded = expand_word((*token)->data);
	splited = split_set(expanded, " \t");
	free(expanded);
	i = 0;
	new_tokens = NULL;
	while (splited && splited[i])
	{
		new = new_token(TK_WORD, ft_strdup(splited[i]));
		addback_token(&new_tokens, new);
		i++;
	}
	ft_2darraydel(splited);
	return (new_tokens);
}

char	*replace_env_vars(char *str)
{
	size_t	i;
	char	*out;
	size_t	len;

	out = NULL;
	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			process_doller(str, &i, &out);
		}
		else
		{
			len = ft_calc_next_str(&str[i], "$");
			out = ft_strjoin_safe(out, ft_substr(&str[i], 0, len), 1, 1);
			i += len;
		}
	}
	return (out);
}
