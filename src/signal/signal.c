/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:23:17 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/14 20:17:46 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"

int		g_signal;

void	sig_handler_while_child(int sig)
{
	g_signal = sig;
	if (sig == SIGQUIT)
	{
		printf("Quit (core dumped)\n");
	}
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
	}
}

void	sig_int_handler(int sig)
{
	char	*prompt;

	if (sig == SIGINT)
	{
		g_signal = sig;
		rl_on_new_line();
		rl_replace_line("", 0);
		prompt = get_shell_prompt(0);
		printf("\n%s", prompt);
		rl_redisplay();
		free(prompt);
	}
	return ;
}

void	set_signal_handlers(__sighandler_t int_handler,
		__sighandler_t quit_handler)
{
	if (signal(SIGINT, int_handler) == SIG_ERR || signal(SIGQUIT,
			quit_handler) == SIG_ERR)
	{
		perror("signal");
	}
	return ;
}
