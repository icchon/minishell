/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:23:17 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/14 08:44:19 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"

void	sig_int_handler(int sig)
{
	char	*prompt;

	if (sig == SIGINT)
	{
		grobal_status(SET, 130);
		rl_on_new_line();
		rl_replace_line("", 0);
		prompt = get_shell_prompt(0);
		printf("\n%s", prompt);
		rl_redisplay();
		free(prompt);
		// write(1, "\n", 1);
	}
	return ;
}

void	set_signal(void)
{
	t_sigaction	act_c;
	t_sigaction	act_d;

	ft_bzero(&act_c, sizeof(t_sigaction));
	act_c.sa_handler = sig_int_handler;
	sigemptyset(&act_c.sa_mask);
	//act_c.sa_flags = SA_RESETHAND;
	sigaction(SIGINT, &act_c, NULL);
	ft_bzero(&act_d, sizeof(t_sigaction));
	act_d.sa_handler = SIG_IGN;
	sigemptyset(&act_d.sa_mask);
	//act_d.sa_flags = SA_RESETHAND;
	sigaction(SIGQUIT, &act_d, NULL);
	return ;
}
