/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:32:51 by tkitago           #+#    #+#             */
/*   Updated: 2025/02/14 08:20:43 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	valid_export(char *key)
{
	int	i;

	i = 0;
	if (!key)
		return (1);
	while (key[i])
	{
		if (ft_isalnum(key[i]) || key[i] == '_')
			i++;
		else
			return (1);
	}
	return (0);
}

int	check_export_no_equal(char *key, t_env **env_lst)
{
	if (valid_export(key))
	{
		ft_dprintf(STDERR_FILENO, "export: `%s': not a valid identifier\n", key);
		return (1);
	}
	if (!find_env(*env_lst, key))
	{
		append_env_noequal(env_lst, key, "");
	}
	return (0);
}

int	check_export_line(char *line, t_env **env_lst)
{
	char	*check_plus;

	if ((ft_isalpha(line[0]) || line[0] == '_'))
	{
		check_plus = ft_strstr(line, "+=");
		if (check_plus)
			return (check_export_plus(line, check_plus, env_lst));
		else if (ft_strchr(line, '='))
			return (check_export_equal(line, env_lst));
		return (check_export_no_equal(line, env_lst));
	}
	else
	{
		ft_dprintf(STDERR_FILENO, "export: `%s': not a valid identifier\n", line);
		return (1);
	}
}

int	check_export_plus(char *line, char *check_plus, t_env **env_lst)
{
	char	*key;
	char	*value;

	key = extract_key_plus(line);
	value = extract_value(line);
	if (!ft_isalnum(*(check_plus - 1)) || valid_export(key))
	{
		ft_dprintf(STDERR_FILENO, "export: `%s': not a valid identifier\n", line);
		free(key);
		return (1);
	}
	if (!find_env(*env_lst, key))
		append_env(env_lst, key, value);
	else
		util_setenv(env_lst, key, value, 1);
	free(key);
	free(value);
	return (0);
}

int	check_export_equal(char *line, t_env **env_lst)
{
	char	*key;
	char	*value;

	key = extract_key(line);
	value = extract_value(line);
	if (valid_export(key))
	{
		ft_dprintf(STDERR_FILENO, "export: `%s': not a valid identifier\n", line);
		free(key);
		return (1);
	}
	util_setenv(env_lst, key, value, 0);
	free(key);
	free(value);
	return (0);
}
