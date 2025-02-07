#include "minishell.h"

char	**grobal_env(int get_or_set, ...)
{
	va_list		ap;
	static char	**g_env = NULL;
	char		**env;

	va_start(ap, get_or_set);
	env = va_arg(ap, char **);
	va_end(ap);
	if (get_or_set == GET)
	{
		return (g_env);
	}
	else
	{
		g_env = env;
	}
	return (g_env);
}

t_env	*grobal_envlist(int get_or_set, ...)
{
	va_list			ap;
	static t_env	*g_env = NULL;
	t_env			*env;

	va_start(ap, get_or_set);
	env = va_arg(ap, t_env *);
	va_end(ap);
	if (get_or_set == GET)
	{
		return (g_env);
	}
	else
	{
		g_env = env;
	}
	return (g_env);
}

char	*grobal_tmpfile(int get_or_set, ...)
{
	va_list		ap;
	static char	*g_tmpfile = NULL;
	char		*tmpfile;

	va_start(ap, get_or_set);
	tmpfile = va_arg(ap, char *);
	va_end(ap);
	if (get_or_set == GET)
	{
		return (g_tmpfile);
	}
	else
	{
		g_tmpfile = tmpfile;
	}
	return (g_tmpfile);
}

t_status	grobal_status(int get_or_set, ...)
{
	va_list			ap;
	static t_status	g_status = EXIT_SUCCESS;
	t_status		status;

	va_start(ap, get_or_set);
	status = va_arg(ap, int);
	va_end(ap);
	if (get_or_set == GET)
	{
		return (g_status);
	}
	else
	{
		g_status = status;
	}
	return (g_status);
}
