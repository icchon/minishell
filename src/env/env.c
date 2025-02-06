#include "env.h"

t_env	*new_env_node(const char *env)
{
	t_env	*node;

	node = malloc(sizeof(t_env));
	if (!node)
		exit(EXIT_FAILURE);
	node->value = ft_strdup(env);
	if (!node->value)
	{
		free(node);
		exit(EXIT_FAILURE);
	}
	node->next = NULL;
	return (node);
}

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

void	print_env_list(t_env *env_list)
{
	while (env_list)
	{
		printf("%s\n", env_list->value);
		env_list = env_list->next;
	}
}

void	free_env_list(t_env *env_list)
{
	t_env	*tmp;

	while (env_list)
	{
		tmp = env_list;
		env_list = env_list->next;
		free(tmp->value);
		free(tmp);
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
