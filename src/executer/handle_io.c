/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_io.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:03:33 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/12 07:49:28 by kaisobe          ###   ########.fr       */
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
		return (0);
	}
	return (1);
}

int	check_fds(t_redirect *redirect)
{
	int	res;
	int	is_valid_fds;

	is_valid_fds = 1;
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
				is_valid_fds = 0;
				print_error(redirect->data, "Permission denied", 1);
			}
		}
		else if (redirect->type == TK_INPUT_FILE)
		{
			is_valid_fds = 0;
			print_error(redirect->data, "No such file or directory", 1);
		}
		redirect = redirect->next;
	}
	return (is_valid_fds);
}
