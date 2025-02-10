/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:32:26 by tkitago           #+#    #+#             */
/*   Updated: 2025/02/11 07:59:34 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static int	go_home(t_env **env_lst)
{
	char	*home;
	char	old_wd[PATH_MAX];
	char	new_home_wd[PATH_MAX];

	home = getenv("HOME");
	if (!home || !home[0])
	{
		ft_putendl_fd("cd: HOME not set\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (!getcwd(old_wd, sizeof(old_wd)))
		return (EXIT_FAILURE);
	if (chdir(home))
		return (EXIT_FAILURE);
	if (!getcwd(new_home_wd, sizeof(new_home_wd)))
		return (EXIT_FAILURE);
	if (util_setenv(env_lst, "OLDPWD", old_wd, 0))
		return (EXIT_FAILURE);
	if (util_setenv(env_lst, "PWD", new_home_wd, 0))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	cd_check_ac(int ac, t_env **env_lst)
{
	int	flg_cd_home;

	if (ac == 1)
	{
		flg_cd_home = go_home(env_lst);
		return (flg_cd_home);
	}
	else if (ac > 2)
	{
		ft_putendl_fd(" cd: too many arguments", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	return (2);
}

static int	cd_change_dir(char *path, t_env **env_lst)
{
	char	old_wd[PATH_MAX];
	char	new_wd[PATH_MAX];

	if (!getcwd(old_wd, sizeof(old_wd)))
		return (EXIT_FAILURE);
	if (chdir(path))
	{
		printf("cd: %s: No such file or directory\n", path);
		return (EXIT_FAILURE);
	}
	if (!getcwd(new_wd, sizeof(new_wd)))
		return (EXIT_FAILURE);
	if (util_setenv(env_lst, "OLDPWD", old_wd, 0))
		return (EXIT_FAILURE);
	if (util_setenv(env_lst, "PWD", new_wd, 0))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	builtin_cd(int ac, char *av[], t_env **env_lst)
{
	int	exit_flg;

	exit_flg = cd_check_ac(ac, env_lst);
	if (exit_flg != 2)
		return (exit_flg);
	return (cd_change_dir(av[1], env_lst));
}
