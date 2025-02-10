#include "minishell.h"

t_env	*find_env(t_env *env_lst, const char *key)
{
	t_env	*node;

	node = env_lst;
	while (node)
	{
		if (ft_isequal(node->key, (char *)key))
		{
			return (node);
		}
		node = node->next;
	}
	return (NULL);
}

int	append_env(t_env **env_lst, const char *name, const char *value)
{
	t_env	*new_env;

	new_env = new_env_node((const char *)concat_key_value((char *)name,
				(char *)value));
	addback_env(env_lst, new_env);
	return (EXIT_SUCCESS);
}

int	util_setenv(t_env **env_lst, const char *name, const char *value,
		int append_flg)
{
	t_env	*target;
	char	*tmp;

	if (!name || !name[0])
		return (EXIT_FAILURE);
	if (!value)
		value = "";
	target = find_env(*env_lst, name);
	if (!target)
	{
		append_env(env_lst, name, value);
	}
	else
	{
		tmp = target->value;
		if (!append_flg)
			target->value = ft_strdup(value);
		else
			target->value = ft_strjoin(target->value, (char *)value);
		free(tmp);
		tmp = target->line;
		target->line = concat_key_value(target->key, target->value);
		free(tmp);
	}
	return (EXIT_SUCCESS);
}
// new_varもt_envにする必要ある？
