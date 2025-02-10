
#include "minishell.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char	*h;
	const char	*n;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack)
	{
		if (*haystack == *needle)
		{
			h = haystack;
			n = needle;
			while (*n && (*h == *n))
			{
				h++;
				n++;
			}
			if (!*n)
				return ((char *)haystack);
		}
		haystack++;
	}
	return (NULL);
}

void	put_env_export(t_env *env_lst)
{
	t_env	*node;

	node = env_lst;
	while (node)
	{
		printf("declare -x %s\n", node->line);
		node = node->next;
	}
}

char	*concat_key_value_noequal(const char *key, const char *value)
{
	char	*out;
	size_t	len;

	len = ft_strlen(key) + ft_strlen(value) + 1;
	out = ft_strjoin_safe((char *)key, (char *)value, 1, 1);
	return (out);
}

static int	append_env_noequal(t_env **env_lst, const char *name,
		const char *value)
{
	t_env	*new_env;

	new_env = new_env_node(concat_key_value_noequal(name, value));
	addback_env(env_lst, new_env);
	return (EXIT_SUCCESS);
}

static int	check_export_plus(char *line, char *check_plus, t_env **env_lst)
{
	char	*key;
	char	*value;

	if (!ft_isalnum(*(check_plus - 1)))
	{
		printf("export: `%s': not a valid identifier\n", line);
		return (1); // error_flg
	}
	key = extract_key_plus(line);
	value = extract_value(line);
	if (!find_env(*env_lst, key))
		append_env(env_lst, key, value);
	else
		util_setenv(env_lst, key, value, 1);
	free(key);
	free(value);
	return (0);
}

static int	check_export_equal(char *line, t_env **env_lst)
{
	char	*key;
	char	*value;

	key = extract_key(line);
	value = extract_value(line);
	util_setenv(env_lst, key, value, 0);
	free(key);
	free(value);
	return (0);
}

static int	check_export_no_equal(char *line, t_env **env_lst)
{
	t_env	tmp;

	if (!find_env(*env_lst, extract_key(line)))
	{
		tmp.key = ft_strdup(line);
		tmp.value = ft_strdup("");
		append_env_noequal(env_lst, tmp.key, tmp.value);
	}
	return (0);
}

static int	check_export_line(char *line, t_env **env_lst)
{
	char	*check_plus;

	if (!ft_isalpha(line[0]) || line[0] == '_')
	{
		printf("export: `%s': not a valid identifier\n", line);
		return (1); // error_flg
	}
	check_plus = ft_strstr(line, "+=");
	if (check_plus)
		return (check_export_plus(line, check_plus, env_lst));
	else if (ft_strchr(line, '='))
		return (check_export_equal(line, env_lst));
	return (check_export_no_equal(line, env_lst));
}

int	builtin_export(int ac, char *av[], t_env **env_lst)
{
	int	error_flg;
	int	i;

	error_flg = 0;
	if (ac == 1)
	{
		put_env_export(*env_lst);
		return (error_flg);
	}
	i = 1;
	while (i < ac)
	{
		error_flg |= check_export_line(av[i], env_lst);
		i++;
	}
	return (error_flg);
}

// int	builtin_export(int ac, char *av[], t_env **env_lst)
// {
// 	int		i;
// 	t_env	tmp;
// 	char	*check_plus;

// 	int error_flg; //途中でエラーあっても最後まで出したいからフラグでエラー管理
// 	i = 1;
// 	error_flg = 0;
// 	if (ac == 1)
// 	{
// 		put_env_export(*env_lst);
// 		return (error_flg);
// 	}
// 	while (i < ac)
// 	{
// 		if (!ft_isalpha(av[i][0]) || av[i][0] == '_') //変数名判定、エラーでも継続,ok
// 		{
// 			printf("export: `%s': not a valid identifier\n", av[i]);
// 			error_flg = 1;
// 			i++;
// 		}
// 		if (av[i] && (check_plus = strstr(av[i], "+=")))
// 		{
// 			if (!ft_isalnum(*(check_plus - 1)))
// 			{
// 				printf("export: `%s': not a valid identifier\n", av[i]);
// 				error_flg = 1;
// 			}
// 			else if (!find_env(*env_lst, extract_key_plus(av[i]))) //新規+=ok
// 				append_env(env_lst, extract_key_plus(av[i]),
// 					extract_value(av[i]));
// 			else
// 			{
// 				util_setenv(env_lst, extract_key_plus(av[i]),
// 					extract_value(av[i]), 1);
// 			}
// 			i++;
// 		}
// 		else if (av[i] && ft_strchr(av[i], '='))
// 		{
// 			util_setenv(env_lst, extract_key(av[i]), extract_value(av[i]), 0);
// 			i++;
// 		}
// 		else
// 		{
// 			if (av[i] && !find_env(*env_lst, extract_key(av[i])))
// 			{
// 				tmp.key = ft_strdup(av[i]);
// 				tmp.value = ft_strdup("");
// 				append_env_noequal(env_lst, tmp.key, tmp.value);
// 			}
// 			i++;
// 		}
// 	}
// 	return (error_flg);
// }