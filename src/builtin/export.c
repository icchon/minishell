/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:32:04 by tkitago           #+#    #+#             */
/*   Updated: 2025/02/11 08:24:27 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

	out = ft_strjoin((char *)key, (char *)value);
	return (out);
}

int	append_env_noequal(t_env **env_lst, const char *name, const char *value)
{
	t_env	*new_env;
	char	*line;

	line = concat_key_value_noequal(name, value);
	new_env = new_env_node(line);
	free(line);
	addback_env(env_lst, new_env);
	return (EXIT_SUCCESS);
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
// 	export w/ arg is undefined