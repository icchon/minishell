/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_io.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:03:33 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/14 08:49:41 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	handle_io(t_token *redirect)
{
	int	fd;

	while (redirect)
	{
		if (redirect->type == TK_INFILE)
		{
			fd = open(redirect->data, O_RDONLY);
			dup2(fd, STDIN_FILENO);
		}
		else if (redirect->type == TK_OUTFILE)
		{
			fd = open(redirect->data, O_WRONLY | O_TRUNC | O_CREAT,
					S_IRGRP | S_IROTH | S_IWUSR | S_IRUSR);
			dup2(fd, STDOUT_FILENO);
		}
		else if (redirect->type == TK_OUTFILE_APP)
		{
			fd = open(redirect->data, O_WRONLY | O_APPEND | O_CREAT,
					S_IRGRP | S_IROTH | S_IWUSR | S_IRUSR);
			dup2(fd, STDOUT_FILENO);
		}
		close(fd);
		redirect = redirect->next;
	}
	return ;
}

static int	check_existance(char *path)
{
	if (access(path, F_OK) == -1)
	{
		return (0);
	}
	return (1);
}

static int	check_creatable(char *path)
{
	int	fd;

	fd = open(path, O_WRONLY | O_APPEND | O_CREAT,
			S_IRGRP | S_IROTH | S_IWUSR | S_IRUSR);
	if (fd == -1)
	{
		return (0);
	}
	close(fd);
	unlink(path);
	return (1);
}

static int	check_access(t_token *redirect)
{
	int	res;

	if (check_existance(redirect->data))
	{
		res = 0;
		if (redirect->type == TK_INFILE)
			res = access(redirect->data, R_OK);
		else if (redirect->type == TK_OUTFILE)
			res = access(redirect->data, W_OK);
		else if (redirect->type == TK_OUTFILE_APP)
			res = access(redirect->data, W_OK);
		if (res == -1)
		{
			ft_dprintf(STDERR_FILENO, "bash: %s: Permission denied\n",
				redirect->data);
			return (0);
		}
	}
	else if (redirect->type == TK_INFILE || !check_creatable(redirect->data))
	{
		ft_dprintf(STDERR_FILENO, "bash: %s: No such file or directory\n",
			redirect->data);
		return (0);
	}
	return (1);
}

int	check_fds(t_redirect *redirect)
{
	int	is_valid_fds;

	is_valid_fds = 1;
	while (redirect)
	{
		is_valid_fds &= check_access(redirect);
		redirect = redirect->next;
	}
	return (is_valid_fds);
}
