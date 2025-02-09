#include "minishell.h"

static void	process_doller(char *str, size_t *i, char **out)
{
	size_t	len;
	char	*key;

	if (str[*i] == '$')
	{
		len = ft_calc_next_str(&str[++(*i)], "\t\n\v\f\r $");
		key = ft_substr(&str[*i], 0, len);
		if (ft_isequal(key, "?"))
			*out = ft_strjoin_safe(*out, ft_itoa(grobal_status(GET)), 1, 1);
		else
			*out = ft_strjoin_safe(*out, ft_get_env(key, grobal_env(GET)), 1,
					0);
		free(key);
		(*i) += len;
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
			len = ft_calc_next_str(&str[i], "$");
			out = ft_strjoin_safe(out, ft_substr(&str[i], 0, len), 1, 1);
			i += len;
		}
	}
	return (out);
}

static int	is_single_quate(char *str)
{
	if (ft_strlen(str) <= 1)
		return (0);
	return ((str[0] == '\'') && (str[ft_strlen(str) - 1] == '\''));
}

static int	is_double_quate(char *str)
{
	if (ft_strlen(str) <= 1)
		return (0);
	return ((str[0] == '\"') && (str[ft_strlen(str) - 1] == '\"'));
}

static char	*trim_edge(char *str)
{
	char	*out;
	size_t	len;
	size_t	i;

	len = ft_strlen(str) - 2;
	if (len < 0)
		return (NULL);
	out = (char *)ft_calloc((len + 1), sizeof(char));
	i = 0;
	while (i < len)
	{
		out[i] = str[i + 1];
		i++;
	}
	return (out);
}

char	*expand_word(char *str)
{
	int		is_single;
	int		is_double;
	char	*out;
	char	*tmp;

	is_single = is_single_quate(str);
	is_double = is_double_quate(str);
	if (is_single)
	{
		out = trim_edge(str);
	}
	else if (is_double)
	{
		tmp = trim_edge(str);
		out = replace_env_vars(tmp);
		free(tmp);
	}
	else
	{
		out = replace_env_vars(str);
	}
	return (out);
}

// static void	process_single_quate(char *str, size_t *i, char **out)
// {
// 	char	*part;
// 	size_t	len;

// 	(*i)++;
// 	len = ft_calc_next_chr(&str[*i], '\'');
// 	part = ft_substr(&str[*i], 0, len);
// 	*out = ft_strjoin_safe(*out, part, 1, 1);
// 	(*i) += len + 1;
// }

// char	*replace_env_vars_quate(char *str)
// {
// 	size_t	i;
// 	char	*out;
// 	char	*part;
// 	size_t	len;
// 	char	*tmp;

// 	i = 0;
// 	out = NULL;
// 	len = ft_calc_next_chr(&str[i], '\'');
// 	if (str[i] == '\'')
// 		process_single_quate(str, &(i), &out);
// 	while (len > 0)
// 	{
// 		tmp = ft_substr(&str[i], 0, len);
// 		part = replace_env_vars(tmp);
// 		free(tmp);
// 		out = ft_strjoin_safe(out, part, 1, 1);
// 		i += len;
// 		if (str[i] == '\'')
// 			process_single_quate(str, &i, &out);
// 		len = ft_calc_next_chr(&str[i], '\'');
// 	}
// 	return (out);
// }
