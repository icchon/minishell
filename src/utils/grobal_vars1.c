/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grobal_vars1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:23:20 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/14 21:52:46 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

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

t_env	**grobal_envlist(int get_or_set, ...)
{
	va_list			ap;
	static t_env	*g_env = NULL;
	t_env			*env;

	va_start(ap, get_or_set);
	env = va_arg(ap, t_env *);
	va_end(ap);
	if (get_or_set == GET)
	{
		return (&g_env);
	}
	else
	{
		g_env = env;
	}
	return (&g_env);
}

t_list	**grobal_tmpfile(int get_or_set, ...)
{
	va_list			ap;
	static t_list	*g_tmpfiles = NULL;
	char			*tmpfile;
	t_list			*node;

	va_start(ap, get_or_set);
	tmpfile = va_arg(ap, char *);
	va_end(ap);
	if (get_or_set == GET)
	{
		return (&g_tmpfiles);
	}
	else
	{
		node = ft_lstnew(tmpfile);
		ft_lstadd_back(&g_tmpfiles, node);
	}
	return (&g_tmpfiles);
}

void	free_tmpfiles(void)
{
	t_list	**lst;
	t_list	*node;

	lst = grobal_tmpfile(GET);
	node = *lst;
	while (node)
	{
		unlink((char *)node->content);
		node = node->next;
	}
	ft_lstclear(lst, free);
	return ;
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
