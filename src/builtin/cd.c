
#include "minishell.h"
#include <limits.h>

static int	go_home(char *old_wd, char *new_wd)
{
	char	*home;

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
	if (!getcwd(new_wd, sizeof(new_wd)))
		return (EXIT_FAILURE);
	if (setenv("OLDPWD", old_wd, 1))
		return (EXIT_FAILURE);
	if (setenv("PWD", new_wd, 1))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	builtin_cd(int ac, char *av[])
{
	char old_wd[PATH_MAX];
	char new_wd[PATH_MAX];
	int flg_cd;

	if (ac == 1)
		flg_cd = go_home(old_wd, new_wd);
	if (flg_cd)
		return (EXIT_FAILURE);
	if (!getcwd(old_wd, sizeof(old_wd)))
		return (EXIT_FAILURE);
	if (chdir(av[1]))
		return (EXIT_FAILURE);
	if (!getcwd(new_wd, sizeof(new_wd)))
		return (EXIT_FAILURE);
	if (setenv("OLDPWD", old_wd, 1))
		return (EXIT_FAILURE);
	if (setenv("PWD", new_wd, 1))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
