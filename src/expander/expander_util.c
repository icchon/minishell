#include "minishell.h"

static int	ft_calc_back_chr(char *str, char c)
{
	char	*s;

	s = ft_strrchr(str, c);
	if (s == NULL)
	{
		return (-1);
	}
	return (s - str);
}

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
		else if (ft_strlen(key) <= 0)
			*out = ft_strjoin_safe(*out, "$", 1, 0);
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
	int	single_left;
	int	double_left;
	int	single_right;
	int	double_right;

	if (ft_strlen(str) <= 1)
		return (0);
	single_left = ft_calc_next_chr(str, '\'');
	single_right = ft_calc_back_chr(str, '\'');
	double_left = ft_calc_next_chr(str, '\"');
	double_right = ft_calc_back_chr(str, '\"');
	if (single_left < single_right && single_left < double_left
		&& double_right < single_right)
		return (1);
	return (0);
}

static int	is_double_quate(char *str)
{
	int	single_left;
	int	double_left;
	int	single_right;
	int	double_right;

	if (ft_strlen(str) <= 1)
		return (0);
	single_left = ft_calc_next_chr(str, '\'');
	single_right = ft_calc_back_chr(str, '\'');
	double_left = ft_calc_next_chr(str, '\"');
	double_right = ft_calc_back_chr(str, '\"');
	// printf("single : (%d, %d), double : (%d, %d)\n", single_left,
	// single_right,
	// double_left, double_right);
	if (double_left < double_right && double_left < single_left
		&& single_right < double_right)
		return (1);
	return (0);
}

static char	*trim_quate(char *str)
{
	char	*out;
	int		left;
	int		right;
	char	quate;

	if (ft_strlen(str) < 2)
		return (NULL);
	if (!(is_double_quate(str) || is_single_quate(str)))
		return (ft_strdup(str));
	quate = '\'';
	if (is_double_quate(str))
		quate = '"';
	left = ft_calc_next_chr(str, quate);
	right = ft_calc_back_chr(str, quate);
	out = ft_substr(str, 0, left);
	out = ft_strjoin_safe(out, ft_substr(str, left + 1, (right - left - 1)), 1,
			1);
	out = ft_strjoin_safe(out, ft_substr(str, right + 1, (ft_strlen(str) - right
					- 1)), 1, 1);
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
		out = trim_quate(str);
	}
	else if (is_double)
	{
		// printf("double\n");
		tmp = trim_quate(str);
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
