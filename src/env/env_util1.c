#include "env.h"

t_env	*new_env_node(const char *env)
{
	t_env	*node;

	node = xmalloc(sizeof(t_env));
	if (!node)
		exit(EXIT_FAILURE);
	node->line = ft_strdup(env);
	node->key = extract_key(env);
	node->value = extract_value(env);
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
		printf("%s\n", env_list->line);
		env_list = env_list->next;
	}
}
