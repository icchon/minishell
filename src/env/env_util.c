#include "env.h"

char	*extract_key(const char *line)
{
	int	len;

	len = ft_calc_next_chr((char *)line, '=');
	return (ft_substr(line, 0, len));
}

char	*extract_key_plus(const char *line)
{
	int	len;

	len = ft_calc_next_chr((char *)line, '+');
	return (ft_substr(line, 0, len));
}

char	*extract_value(const char *line)
{
	int	len;

	len = ft_calc_next_chr((char *)line, '=');
	return (ft_substr(line, len + 1, ft_strlen(line) - len - 1));
}

char	*concat_key_value(char *key, char *value)
{
	char	*out;
	size_t	len;

	len = ft_strlen(key) + ft_strlen(value) + 1;
	out = xmalloc(sizeof(char) * (len + 1));
	out = ft_strjoin(key, "=");
	out = ft_strjoin_safe((char *)out, (char *)value, 1, 1);
	return (out);
}

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

// void	sort_envlst(t_env **envlst)
// {
// 	(void)envlst;
// 	return ;
// }
