/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_child.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 19:08:21 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/14 22:08:24 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"

void	child_heredoc(int pp[2], char *limiter)
{
	char	*heredoc_res;

	set_signal_handlers(SIG_DFL, SIG_IGN);
	close(pp[READ]);
	dup2(pp[WRITE], STDOUT_FILENO);
	close(pp[WRITE]);
	heredoc_res = here_doc(limiter);
	printf("%s", heredoc_res);
	exit(EXIT_SUCCESS);
}
