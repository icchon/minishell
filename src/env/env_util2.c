#include "minishell.h"

char	*extract_key(const char *line)
{
	int	len;

	len = ft_calc_next_chr((char *)line, '=');
	return (ft_substr(line, 0, len));
}

char	*extract_value(const char *line)
{
	int	len;

	len = ft_calc_next_chr((char *)line, '=');
	return (ft_substr(line, len + 1, ft_strlen(line) - len - 1));
}

char	*concat_key_value(const char *key, const char *value)
{
	char	*out;
	size_t	len;

	len = ft_strlen(key) + ft_strlen(value) + 1;
	out = xmalloc(sizeof(char) * (len + 1));
	out = ft_strjoin(key, "=");
	out = ft_strjoin_safe((char *)out, (char *)value, 1, 0);
	return (out);
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

void	sort_envlst(t_env *envlst)
{
	(void)envlst;
	return ;
}
