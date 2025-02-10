/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:32:51 by tkitago           #+#    #+#             */
/*   Updated: 2025/02/11 08:28:19 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_export_no_equal(char *line, t_env **env_lst)
{
	if (!find_env(*env_lst, line))
	{
		append_env_noequal(env_lst, line, "");
	}
	return (0);
}

int	check_export_line(char *line, t_env **env_lst)
{
	char	*check_plus;

	if (!ft_isalpha(line[0]) || line[0] == '_')
	{
		printf("export: `%s': not a valid identifier\n", line);
		return (1);
	}
	check_plus = ft_strstr(line, "+=");
	if (check_plus)
		return (check_export_plus(line, check_plus, env_lst));
	else if (ft_strchr(line, '='))
		return (check_export_equal(line, env_lst));
	return (check_export_no_equal(line, env_lst));
}

int	check_export_plus(char *line, char *check_plus, t_env **env_lst)
{
	char	*key;
	char	*value;

	if (!ft_isalnum(*(check_plus - 1)))
	{
		printf("export: `%s': not a valid identifier\n", line);
		return (1);
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

int	check_export_equal(char *line, t_env **env_lst)
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
