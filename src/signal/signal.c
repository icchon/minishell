/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:23:17 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/10 15:41:01 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	sig_int_handler(int sig)
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
	}
	return ;
}

void	set_signal(void)
{
	t_sigaction	act_c;
	t_sigaction	act_d;

	bzero(&act_c, sizeof(t_sigaction));
	act_c.sa_handler = sig_int_handler;
	sigemptyset(&act_c.sa_mask);
	sigaction(SIGINT, &act_c, NULL);
	bzero(&act_d, sizeof(t_sigaction));
	act_d.sa_handler = SIG_IGN;
	sigemptyset(&act_d.sa_mask);
	sigaction(SIGQUIT, &act_d, NULL);
	return ;
}
