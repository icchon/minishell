/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_child.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 19:08:21 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/14 19:09:26 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"

void	child_heredoc(int pp[2], char *limiter)
{
	char	*heredoc_res;

	set_signal_handlers(SIG_DFL, SIG_IGN);
	close(pp[READ]);
	heredoc_res = here_doc(limiter);
	dup2(pp[WRITE], STDOUT_FILENO);
	printf("%s", heredoc_res);
	close(pp[WRITE]);
	exit(EXIT_SUCCESS);
}
