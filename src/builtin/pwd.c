/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:32:59 by tkitago           #+#    #+#             */
/*   Updated: 2025/02/10 21:03:37 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <error.h>
#include <stdio.h>

static int	valid_pwd_util1(char *pwd)
{
	if (!pwd || pwd[0] != '/' || ft_strlen(pwd) >= PATH_MAX)
		return (0);
	return (1);
}

static int	valid_pwd_util2(char **component)
{
	int	i;

	i = 0;
	while (component[i])
	{
		if (ft_isequal(component[i], ".") || ft_isequal(component[i], ".."))
			return (0);
		i++;
	}
	return (1);
}

static int	valid_pwd(char *pwd)
{
	char	**component;
	char	*tmp_pwd;

	if (!valid_pwd_util1(pwd))
		return (0);
	tmp_pwd = ft_strdup(pwd);
	if (!tmp_pwd)
		return (0);
	component = ft_split(tmp_pwd, '/');
	free(tmp_pwd);
	if (!valid_pwd_util2(component))
	{
		ft_2darraydel(component);
		return (0);
	}
	ft_2darraydel(component);
	return (1);
}

int	builtin_pwd(char **envp)
{
	char	*cwd_env;

	cwd_env = ft_get_env("PWD", envp);
	if (valid_pwd(cwd_env))
	{
		ft_putendl_fd(cwd_env, STDOUT_FILENO);
	}
	else
	{
		ft_putendl_fd(cwd_env, STDOUT_FILENO);
	}
	return (EXIT_SUCCESS);
}
// w/option work like -L
// if (!-L), work like -P
