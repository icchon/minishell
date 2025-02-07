#include "minishell.h"

char	*replace_env_vars(char *str, char **env)
{
	size_t	i;
	char	*key;
	char	*out;
	size_t	len;

	out = NULL;
	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			len = ft_calc_next_str(&str[++i], "\t\n\v\f\r \"$");
			key = ft_substr(&str[i], 0, len);
			if (ft_isequal(key, "?"))
				out = ft_strjoin_safe(out, ft_itoa(grobal_status(GET)), 1, 1);
			out = ft_strjoin_safe(out, ft_get_env(key, env), 1, 0);
			free(key);
		}
		else
		{
			if (str[i] == '\'' || str[i] == '\"')
				i++;
			len = ft_calc_next_str(&str[i], "$\"");
			out = ft_strjoin_safe(out, ft_substr(&str[i], 0, len), 1, 1);
		}
		i += len;
	}
	return (out);
}

static void	process_single_quate(char *str, size_t *i, char **out)
{
	char	*part;
	size_t	len;

	len = ft_calc_next_chr(&str[*i + 1], '\'');
	part = ft_substr(&str[*i], 0, len + 1);
	*out = ft_strjoin_safe(*out, part, 1, 1);
	(*i) += len + 2;
}

char	*replace_env_vars_quate(char *str, char **env)
{
	size_t	i;
	char	*out;
	char	*part;
	size_t	len;
	char	*tmp;

	i = 0;
	out = NULL;
	len = ft_calc_next_chr(&str[i], '\'');
	if (str[i] == '\'')
	{
		i++;
		process_single_quate(str, &(i), &out);
	}
	while (len > 0)
	{
		tmp = ft_substr(&str[i], 0, len);
		part = replace_env_vars(tmp, env);
		free(tmp);
		out = ft_strjoin_safe(out, part, 1, 1);
		i += len;
		if (str[i] == '\'')
		{
			i++;
			process_single_quate(str, &i, &out);
		}
		len = ft_calc_next_chr(&str[i], '\'');
	}
	return (out);
}
