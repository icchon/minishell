/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:32:04 by tkitago           #+#    #+#             */
/*   Updated: 2025/02/10 20:59:28 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

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

int	append_env_noequal(t_env **env_lst, const char *name, const char *value)
{
	t_env	*new_env;

	new_env = new_env_node(concat_key_value_noequal(name, value));
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