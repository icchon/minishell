#include "minishell.h"

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
