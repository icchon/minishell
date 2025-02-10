/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_env_util2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:58:24 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/10 20:13:39 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_env	*create_env_list(char **envp)
{
	t_env	*head;
	t_env	*tail;
	t_env	*node;

	head = NULL;
	tail = NULL;
	while (*envp)
	{
		node = new_env_node(*envp);
		if (!head)
		{
			head = node;
			tail = node;
		}
		else
		{
			tail->next = node;
			tail = node;
		}
		envp++;
	}
	return (head);
}

void	free_env_node(t_env *env_node)
{
	if (!env_node)
		return ;
	free(env_node->line);
	free(env_node->key);
	free(env_node->value);
	free(env_node);
}

void	free_env_list(t_env *env_list)
{
	t_env	*tmp;

	while (env_list)
	{
		tmp = env_list;
		env_list = env_list->next;
		free_env_node(tmp);
	}
}
