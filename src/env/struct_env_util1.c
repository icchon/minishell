/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_env_util1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:58:16 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/14 06:52:56 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_env	*new_env_node(const char *env)
{
	t_env	*node;

	node = xmalloc(sizeof(t_env));
	node->line = ft_strdup(env);
	node->key = extract_key(env);
	node->value = extract_value(env);
	node->next = NULL;
	return (node);
}

t_env	*last_env(t_env *env_list)
{
	t_env	*node;

	node = env_list;
	if (!node)
		return (NULL);
	while (node->next)
	{
		node = node->next;
	}
	return (node);
}

void	addback_env(t_env **env_list, t_env *new_env)
{
	t_env	*last;

	last = last_env(*env_list);
	if (!last)
	{
		*env_list = new_env;
	}
	else
	{
		last->next = new_env;
	}
	return ;
}

int	env_size(t_env *envlist)
{
	t_env	*node;
	int		size;

	node = envlist;
	size = 0;
	while (node)
	{
		size++;
		node = node->next;
	}
	return (size);
}

void	print_env_list(t_env *env_list)
{
	while (env_list)
	{
		printf("%s\n", env_list->line);
		env_list = env_list->next;
	}
}
