
#include "minishell.h"
#include <limits.h>

static int	go_home(void)
{
	char	*home;
	char	old_wd[PATH_MAX];
	char	new_home_wd[PATH_MAX];
	t_env	**env_lst;

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
	// if (setenv("OLDPWD", old_wd, 1))
	if (util_setenv(&env_lst, "OLDPWD", old_wd, 1))
		return (EXIT_FAILURE);
	// if (setenv("PWD", new_home_wd, 1))
	if (util_setenv(&env_lst, "PWD", new_home_wd, 1))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	builtin_cd(int ac, char *av[])
{
	char	old_wd[PATH_MAX];
	char	new_wd[PATH_MAX];
	int		flg_cd;
	t_env	**env_lst;

	if (ac == 1)
	{
		flg_cd = go_home();
		if (flg_cd)
			return (EXIT_FAILURE);
	}
	if (!getcwd(old_wd, sizeof(old_wd)))
		return (EXIT_FAILURE);
	if (chdir(av[1]))
		return (EXIT_FAILURE);
	if (!getcwd(new_wd, sizeof(new_wd)))
		return (EXIT_FAILURE);
	if (util_setenv(&env_lst, "OLDPWD", old_wd, 1))
		return (EXIT_FAILURE);
	// if (setenv("OLDPWD", old_wd, 1))
	// if (setenv("PWD", new_wd, 1))
	if (util_setenv(&env_lst, "PWD", new_wd, 1))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
