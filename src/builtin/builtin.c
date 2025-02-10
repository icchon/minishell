#include "builtin.h"

int	is_builtin(char *cmd)
{
	if (ft_isequal(cmd, "cd"))
		return (1);
	if (ft_isequal(cmd, "echo"))
		return (1);
	if (ft_isequal(cmd, "env"))
		return (1);
	if (ft_isequal(cmd, "exit"))
		return (1);
	if (ft_isequal(cmd, "export"))
		return (1);
	if (ft_isequal(cmd, "pwd"))
		return (1);
	if (ft_isequal(cmd, "unset"))
		return (1);
	return (0);
}

t_status	builtin(char *av[])
{
	t_env	**env_lst;

	env_lst = grobal_envlist(GET);
	if (ft_isequal(av[0], "cd"))
		return (builtin_cd(ft_strslen((const char **)av), av,
				grobal_envlist(GET)));
	if (ft_isequal(av[0], "echo"))
		return (builtin_echo(ft_strslen((const char **)av), av));
	if (ft_isequal(av[0], "env"))
		return (builtin_env(*grobal_envlist(GET)));
	if (ft_isequal(av[0], "exit"))
		return (builtin_exit(ft_strslen((const char **)av), av,
				grobal_status(GET)));
	if (ft_isequal(av[0], "export"))
		return (builtin_export(ft_strslen((const char **)av), av,
				grobal_envlist(GET)));
	if (ft_isequal(av[0], "pwd"))
		return (builtin_pwd(grobal_env(GET)));
	if (ft_isequal(av[0], "unset"))
		return (builtin_unset(ft_strslen((const char **)av), av,
				grobal_envlist(GET)));
	return (EXIT_FAILURE);
}
