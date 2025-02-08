#include "minishell.h"

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
	if (ft_isequal(av[0], "cd"))
		return (builtin_cd(ft_strslen((const char **)av), av));
	if (ft_isequal(av[0], "echo"))
		return (builtin_echo(ft_strslen((const char **)av), av));
	if (ft_isequal(av[0], "env"))
		return (builtin_env(grobal_env(GET)));
	if (ft_isequal(av[0], "exit"))
		return (builtin_exit(ft_strslen((const char **)av), av,
				grobal_status(GET)));
	if (ft_isequal(av[0], "export"))
		return (EXIT_FAILURE);
	if (ft_isequal(av[0], "pwd"))
	{
		printf("pwd start\n");
		builtin_pwd();
		printf("pwd end\n");
		return (EXIT_SUCCESS);
	}
	if (ft_isequal(av[0], "unset"))
		return (builtin_unset(ft_strslen((const char **)av), av,
				grobal_envlist(GET)));
	return (EXIT_FAILURE);
}
