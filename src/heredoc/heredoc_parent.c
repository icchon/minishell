/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_parent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 19:04:42 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/14 20:01:36 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"

static char	*get_child_heredoc_file(int pp[2])
{
	char	buff[HEREDOC_BUFFERSIZE];
	char	*input_file;
	int		fd;

	close(pp[WRITE]);
	ft_bzero(buff, HEREDOC_BUFFERSIZE);
	read(pp[READ], buff, HEREDOC_BUFFERSIZE);
	close(pp[READ]);
	input_file = ft_create_random_file(".", ".tmp");
	fd = open(input_file, O_WRONLY | O_APPEND | O_CREAT,
			S_IRGRP | S_IROTH | S_IWUSR | S_IRUSR);
	ft_dprintf(fd, buff);
	close(fd);
	grobal_tmpfile(SET, input_file);
	return (input_file);
}

static void	create_file_redirection(t_redirect *redirect)
{
	char	*limiter;
	int		pp[2];

	limiter = redirect->data;
	pipe(pp);
	if (fork() == 0)
		child_heredoc(pp, limiter);
	wait(NULL);
	close(pp[WRITE]);
	if (g_signal != 0)
	{
		close(pp[READ]);
		return ;
	}
	redirect->data = get_child_heredoc_file(pp);
	redirect->type = TK_INFILE;
	free(limiter);
	close(pp[READ]);
	return ;
}

void	exec_heredoc(t_astnode *node)
{
	t_redirect	*redirect;

	if (!node)
		return ;
	redirect = node->redirects;
	while (redirect)
	{
		if (redirect->type == TK_LIMITER)
		{
			create_file_redirection(redirect);
		}
		redirect = redirect->next;
	}
	exec_heredoc(node->left);
	exec_heredoc(node->right);
}
