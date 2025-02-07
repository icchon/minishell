
#include "minishell.h"
#include <limits.h>

int	builtin_cd(int ac, char *av[])
{
	char	old_wd[PATH_MAX];
	char	new_wd[PATH_MAX];
	char	*home;

	if (ac == 1)
	{
		home = getenv("HOME");
		if (!home || !home[0])
		{
			ft_putendl_fd("cd: HOME not set\n", STDERR_FILENO);
			return (EXIT_FAILURE);
		}
		if (chdir(home))
			return (EXIT_FAILURE);
		return (EXIT_SUCCESS);
	}
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
