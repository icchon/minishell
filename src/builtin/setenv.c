
#include "minishell.h"

static int	count_env(t_env **env_lst)
{
	int	count_env;

	count_env = 0;
	while (env_lst[count_env])
		count_env++;
	return (count_env);
}

t_env	**find_env(t_env **env_lst, const char *name, size_t name_len)
{
	int	i;

	i = 0;
	while (env_lst[i])
	{
		if ((!ft_strncmp(env_lst[i], name, name_len))
			&& (env_lst[i][name_len].value == '='))
			return (&env_lst[i]);
		i++;
	}
	return (NULL);
}

static char	*env_cpy(const char *name, const char *value, size_t name_len,
		size_t value_len)
{
	char	*add_env;

	add_env = malloc(name_len + value_len + 2);
	if (!add_env)
		return (NULL);
	ft_memcpy(add_env, name, name_len);
	add_env[name_len] = '=';
	ft_memcpy(add_env + name_len + 1, value, value_len);
	add_env[name_len + value_len + 1] = '\0';
	return (add_env);
}

static int	append_env(t_env ***env_lst, const char *name, const char *value,
		size_t name_len)
{
	int		count;
	int		i;
	t_env	**new_env;
	char	*new_var;

	count = count_env(*env_lst);
	new_env = malloc(sizeof(char *) * (count + 2));
	if (!new_env)
		return (EXIT_FAILURE);
	i = -1;
	while (i++ < count)
		new_env[i]->value = (*env_lst)[i]->value;
	new_var = env_cpy(name, value, name_len, ft_strlen(value));
	if (!new_var)
	{
		free(new_env);
		return (EXIT_FAILURE);
	}
	new_env[count]->value = new_var;
	new_env[count + 1]->value = NULL;
	free(*env_lst);
	*env_lst = new_env;
	return (EXIT_SUCCESS);
}

int	util_setenv(t_env ***env_lst, const char *name, const char *value,
		int append_flg)
{
	char	*new_var;
	size_t	name_len;
	size_t	value_len;
	t_env	**target;

	if (!name || !name[0])
		return (EXIT_FAILURE);
	if (!value)
		value = "";
	name_len = ft_strlen(name);
	value_len = ft_strlen(value);
	target = find_env(*env_lst, name, name_len);
	if (target)
	{
		if (!append_flg)
			return (EXIT_SUCCESS);
		new_var = env_cpy(name, value, name_len, value_len);
		if (!new_var)
			return (EXIT_FAILURE);
		free(*target);
		*target = new_var;
		return (EXIT_SUCCESS);
	}
	else
		return (append_env(env_lst, name, value, name_len));
}
// new_varもt_envにする必要ある？
