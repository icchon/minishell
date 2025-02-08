
#include "minishell.h"

static t_env	*find_env(t_env *env_lst, const char *key)
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

static int	append_env(t_env **env_lst, const char *name, const char *value)
{
	t_env	*new_env;

	new_env = new_env_node(concat_key_value(name, value));
	addback_env(env_lst, new_env);
	return (EXIT_SUCCESS);
}

int	util_setenv(t_env **env_lst, const char *name, const char *value,
		int append_flg)
{
	t_env	*target;

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
		if (!append_flg)
		{
			target->value = ft_strdup(value);
		}
		else
		{
			target->value = ft_strjoin_safe(target->value, (char *)value, 1, 0);
		}
		target->line = concat_key_value(target->key, target->value);
	}
	return (EXIT_SUCCESS);
}
// new_varもt_envにする必要ある？
