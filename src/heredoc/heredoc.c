/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:19:37 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/14 14:51:25 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"

static char	*here_doc_read(t_bufferio *stdin, char *delimited, size_t *line)
{
	char	*temp;

	ft_putstr_fd("> ", STDOUT_FILENO);
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

char	*process_heredoc(char *limiter)
{
	char	*res;
	char	*input_file;
	int		fd;

	res = here_doc(limiter);
	input_file = ft_create_random_file(".", ".tmp");
	fd = open(input_file, O_WRONLY | O_APPEND | O_CREAT,
			S_IRGRP | S_IROTH | S_IWUSR | S_IRUSR);
	ft_putstr_fd(res, fd);
	free(res);
	close(fd);
	return (input_file);
}

void	exec_heredoc(t_astnode *node)
{
	t_redirect	*redirect;
	char		*limiter;
	//char		*input_file;
	char		*heredoc_res;
	pid_t		pid;
	int			pp[2];
	char		buff[GNL_BUFFSIZE];

	if (!node)
		return ;
	redirect = node->redirects;
	while (redirect)
	{
		if (redirect->type == TK_LIMITER)
		{
			limiter = redirect->data;
			// limiter = ft_strtrim_safe(limiter, "'\"");
			// input_file = process_heredoc(limiter);
			pipe(pp);
			pid = fork();
			if (pid == 0)
			{
				close(pp[READ]);
				heredoc_res = here_doc(limiter);
				printf("%s\n", heredoc_res);
				exit(EXIT_SUCCESS);
			}
			wait(NULL);
			close(WRITE);
			read(pp[READ], buff, GNL_BUFFSIZE);
			printf("recieved : ");
			printf("%s\n", buff);
			printf("-----------------\n");
			// grobal_tmpfile(SET, input_file);
			// redirect->data = ft_strdup(input_file);
			// redirect->type = TK_INFILE;
			free(limiter);
		}
		redirect = redirect->next;
	}
	exec_heredoc(node->left);
	exec_heredoc(node->right);
}
