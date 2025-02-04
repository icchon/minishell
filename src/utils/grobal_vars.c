#include "minishell.h"

char	**grobal_env(int get_or_set, char **env)
{
	static char	**g_env = NULL;

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



char	*grobal_tmpfile(int get_or_set, char *tmpfile)
{
	static char	*g_tmpfile = NULL;

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
