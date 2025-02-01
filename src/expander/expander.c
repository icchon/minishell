/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 13:39:35 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/01 09:11:10 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*replace_env_vars(char *str, char **env)
{
	size_t	i;
	char	*key;
	char	*out;
	size_t	len;

	out = NULL;
	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			len = ft_calc_next_str(&str[++i], "\t\n\v\f\r $");
			key = ft_substr(&str[i], 0, len);
			out = ft_strjoin_safe(out, ft_get_env(key,
						env), 1, (free(key), 0));
		}
		else
		{
			len = ft_calc_next_chr(&str[i], '$');
			out = ft_strjoin_safe(out, ft_substr(&str[i], 0, len), 1, 1);
		}
		i += len;
	}
	return (out);
}

static void	process_single_quate(char *str, size_t *i, char **out)
{
	size_t	len;
	char	*part;

	len = ft_calc_next_chr(&str[*i + 1], '\'');
	part = ft_substr(&str[*i], 0, len + 2);
	*out = ft_strjoin_safe(*out, part, 1, 1);
	(*i) += len + 2;
}

static char	*replace_env_vars_quate(char *str, char **env)
{
	size_t	i;
	char	*out;
	char	*part;
	size_t	len;
	char	*tmp;

	i = 0;
	out = NULL;
	len = ft_calc_next_chr(&str[i], '\'');
	if (str[i] == '\'')
		process_single_quate(str, &i, &out);
	while (len > 0)
	{
		tmp = ft_substr(&str[i], 0, len);
		part = replace_env_vars(tmp, env);
		free(tmp);
		out = ft_strjoin_safe(out, part, 1, 1);
		i += len;
		if (str[i] == '\'')
			process_single_quate(str, &i, &out);
		len = ft_calc_next_chr(&str[i], '\'');
	}
	return (out);
}

void	expander(t_astnode *node)
{
	t_token	*token;
	char	*tmp;
	size_t	cnt;

	cnt = 0;
	if (!node)
		return ;
	token = node->cmd;
	while (cnt < 3)
	{
		while (token)
		{
			tmp = token->data;
			token->data = replace_env_vars_quate(tmp, grobal_env(GET, NULL));
			token = token->next;
			free(tmp);
		}
		cnt++;
		if (cnt == 1)
			token = node->redirects;
		else
			token = node->args;
	}
	expander(node->left);
	expander(node->right);
}
