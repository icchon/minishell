/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:10:15 by tkitago           #+#    #+#             */
/*   Updated: 2025/02/03 07:32:33 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <error.h>
#include <stdio.h>

static int	valid_pwd(char *pwd)
{
	char	**component;
	char	*tmp_pwd;
	int		i;

	i = 0;
	if (!pwd || pwd[0] != '/' || ft_strlen(pwd) >= PATH_MAX)
		return (EXIT_FAILURE);
	if (!(tmp_pwd = ft_strdup(pwd)))
		return (EXIT_FAILURE);
	if (!(component = ft_split(tmp_pwd, '/')))
	{
		free(tmp_pwd);
		return (EXIT_FAILURE);
	}
	while (component[i++])
	{
		if (!ft_strcmp(component[i], ".") || !ft_strcmp(component[i], ".."))
		{
			free(tmp_pwd);
			return (EXIT_FAILURE);
		}
		component++;
	}
	free(tmp_pwd);
	return (EXIT_SUCCESS);
}

int	builtin_pwd(void)
{
	char	cwd[PATH_MAX];
	char	*cwd_env;

	cwd_env = getenv("PWD");
	if (cwd_env && !valid_pwd(cwd_env))
	{
		ft_putendl_fd(cwd_env, STDOUT_FILENO);
		return (EXIT_SUCCESS);
	}
	if (getcwd(cwd, sizeof(cwd)))
	{
		ft_putendl_fd(cwd, STDOUT_FILENO);
		return (EXIT_SUCCESS);
	}
	else
	{
		perror("pwd");
		return (EXIT_FAILURE);
	}
}
// optionなしだと-Lに合わせるっぽい, manとposixで違う
// https://pubs.opengroup.org/onlinepubs/9699919799/utilities/pwd.html
// -Lだとシンボリック関係なくPWD環境変数に基づいて絶対パス表示
// シンボリックリンクはlstatで取れそうだけどどういうときに-Pになるかわからないし
// 沼だからやらない
// getcwd 引数ない(NULL)のときmallocで領域確保
