/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:23:17 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/14 13:50:06 by kaisobe          ###   ########.fr       */
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

void	set_signal(void)
{
	// t_sigaction	act_c;
	// t_sigaction	act_d;
	// ft_bzero(&act_c, sizeof(t_sigaction));
	// act_c.sa_handler = sig_int_handler;
	// sigemptyset(&act_c.sa_mask);
	// // act_c.sa_flags = SA_RESETHAND;
	// sigaction(SIGINT, &act_c, NULL);
	// ft_bzero(&act_d, sizeof(t_sigaction));
	// act_d.sa_handler = SIG_IGN;
	// sigemptyset(&act_d.sa_mask);
	// // act_d.sa_flags = SA_RESETHAND;
	// sigaction(SIGQUIT, &act_d, NULL);
	signal(SIGINT, sig_int_handler);
	signal(SIGQUIT, SIG_IGN);
	return ;
}
