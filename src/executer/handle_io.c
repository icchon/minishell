/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_io.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:03:33 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/11 07:41:56 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	handle_io(t_token *redirect)
{
	int	fd;

	while (redirect)
	{
		if (redirect->type == TK_INPUT_FILE)
		{
			fd = open(redirect->data, O_RDONLY);
			dup2(fd, STDIN_FILENO);
		}
		else if (redirect->type == TK_OUTPUT_FILE)
		{
			fd = open(redirect->data, O_WRONLY | O_TRUNC | O_CREAT,
					S_IRGRP | S_IROTH | S_IWUSR | S_IRUSR);
			dup2(fd, STDOUT_FILENO);
		}
		else if (redirect->type == TK_OUTPUT_FILE_APPEND)
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
		print_error(path, "No such file or directory", 1);
		return (0);
	}
	return (1);
}

t_status	check_fds(t_redirect *redirect)
{
	int			res;
	t_status	status;

	status = EXIT_SUCCESS;
	while (redirect)
	{
		if (check_existance(redirect->data))
		{
			if (redirect->type == TK_INPUT_FILE)
				res = access(redirect->data, R_OK);
			else if (redirect->type == TK_OUTPUT_FILE)
				res = access(redirect->data, W_OK);
			else if (redirect->type == TK_OUTPUT_FILE_APPEND)
				res = access(redirect->data, W_OK);
			if (res == -1)
			{
				print_error(redirect->data, "Permission denied", 1);
				status = 126;
			}
		}
		redirect = redirect->next;
	}
	return (status);
}
