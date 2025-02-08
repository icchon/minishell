#include "minishell.h"

void	update_grobal_envlist(void)
{
	t_env	*env;

	env = grobal_envlist(GET);
	free_env_list(env);
	env = create_env_list(grobal_env(GET));
	grobal_envlist(SET, env);
	return ;
}

char	**create_env(t_env *envlist)
{
	char	**env;
	int		len;
	int		i;
	t_env	*node;
	char	*value;

	len = env_size(envlist);
	env = (char **)xmalloc(sizeof(char *) * (len + 1));
	node = envlist;
	i = 0;
	while (i < len)
	{
		value = node->value;
		env[i++] = ft_strdup(value);
		node = node->next;
	}
	env[i] = NULL;
	return (env);
}

void	update_grobal_env(void)
{
	char	**env;

	env = grobal_env(GET);
	ft_2darraydel(env);
	env = create_env(grobal_envlist(GET));
	grobal_env(SET, env);
	return ;
}
