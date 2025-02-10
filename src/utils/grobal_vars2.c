/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grobal_vars2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:23:23 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/10 15:23:24 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	update_grobal_envlist(void)
{
	t_env	**env;
	t_env	*new;

	env = grobal_envlist(GET);
	free_env_list(*env);
	new = create_env_list(grobal_env(GET));
	grobal_envlist(SET, new);
	return ;
}

char	**create_env(t_env *envlist)
{
	char	**env;
	int		len;
	int		i;
	t_env	*node;
	char	*line;

	len = env_size(envlist);
	env = (char **)xmalloc(sizeof(char *) * (len + 1));
	node = envlist;
	i = 0;
	while (i < len)
	{
		line = node->line;
		env[i++] = ft_strdup(line);
		node = node->next;
	}
	env[i] = NULL;
	return (env);
}

void	update_grobal_env(void)
{
	char	**env;
	t_env	**env_lst;

	env = grobal_env(GET);
	env_lst = grobal_envlist(GET);
	ft_2darraydel(env);
	env = create_env(*env_lst);
	grobal_env(SET, env);
	return ;
}
