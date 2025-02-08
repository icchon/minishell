#include "minishell.h"

char	*replace_env_status(char *out, char *key)
{
	if (ft_isequal(key, "?"))
		out = ft_strjoin_safe(out, ft_itoa(grobal_status(GET)), 1, 1);
	return (out);
}

static void	process_doller(char *str, size_t *i, char **out)
{
	size_t	len;
	char	*key;

	if (str[*i] == '$')
	{
		len = ft_calc_next_str(&str[++(*i)], "\t\n\v\f\r \"$");
		key = ft_substr(&str[*i], 0, len);
		replace_env_status(*out, key);
		*out = ft_strjoin_safe(*out, ft_get_env(key, grobal_env(GET)), 1, 0);
		free(key);
	}
}

char	*replace_env_vars(char *str)
{
	size_t	i;
	char	*out;
	size_t	len;

	out = NULL;
	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			process_doller(str, &i, &out);
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

	(*i)++;
	len = ft_calc_next_chr(&str[*i + 1], '\'');
	part = ft_substr(&str[*i], 0, len + 1);
	*out = ft_strjoin_safe(*out, part, 1, 1);
	(*i) += len + 2;
}

char	*replace_env_vars_quate(char *str)
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
		process_single_quate(str, &(i), &out);
	while (len > 0)
	{
		tmp = ft_substr(&str[i], 0, len);
		part = replace_env_vars(tmp);
		free(tmp);
		out = ft_strjoin_safe(out, part, 1, 1);
		i += len;
		if (str[i] == '\'')
			process_single_quate(str, &i, &out);
		len = ft_calc_next_chr(&str[i], '\'');
	}
	return (out);
}
