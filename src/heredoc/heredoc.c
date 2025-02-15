/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:19:37 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/15 15:13:25 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"

static void	put_error(size_t line, char *delimited)
{
	if (line)
	{
		ft_putstr_fd("line ", STDERR_FILENO);
		ft_putnbr_fd(line, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	ft_putstr_fd("warning: ", STDERR_FILENO);
	ft_putstr_fd("here-document at line 0 delimited by end-of-file ",
		STDERR_FILENO);
	ft_putstr_fd("(wanted `", STDERR_FILENO);
	ft_putstr_fd(delimited, STDERR_FILENO);
	ft_putstr_fd("')\n", STDERR_FILENO);
}

static int	check_delimited(t_strgen *strgen, char *str, char *delimited,
		size_t delimited_len)
{
	if (!ft_strncmp(str, delimited, delimited_len)
		&& str[delimited_len] == '\n')
	{
		free(str);
		return (1);
	}
	else
	{
		ft_strgenstr(strgen, str);
		free(str);
		return (0);
	}
}

static char	*here_doc_read(t_bufferio *stdin, char *delimited, size_t *line)
{
	char	*temp;

	ft_putstr_fd("> ", STDERR_FILENO);
	temp = ft_readline(stdin);
	if (!temp)
		put_error(*line, delimited);
	(*line)++;
	return (temp);
}

static char	*loop(t_bufferio *stdin, char *delimited)
{
	t_strgen	*strgen;
	size_t		delimited_len;
	size_t		line;
	char		*temp;

	delimited_len = ft_strlen(delimited);
	strgen = ft_strgeninit();
	if (!strgen)
		return (NULL);
	line = 0;
	while (1)
	{
		temp = here_doc_read(stdin, delimited, &line);
		if (!temp)
			break ;
		if (check_delimited(strgen, temp, delimited, delimited_len))
		{
			temp = ft_strgencomp(strgen);
			break ;
		}
	}
	ft_strgendel(strgen);
	return (temp);
}

char	*here_doc(char *delimited)
{
	char		*ret;
	t_bufferio	*stdin;

	stdin = ft_bufferionew(STDIN_FILENO, 0);
	if (!stdin)
	{
		perror("stdin");
		return (NULL);
	}
	ret = loop(stdin, delimited);
	if (!ret && stdin->strgen->error)
		perror("here_doc");
	ft_bufferiodel(stdin, 0);
	return (ret);
}
