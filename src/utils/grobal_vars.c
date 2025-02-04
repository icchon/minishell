/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grobal_vars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:53:46 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/04 17:55:30 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
