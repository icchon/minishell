#include "minishell.h"

static void	sig_int_handler(int sig)
{
	g_signal = sig;
	grobal_status(SET, 130);
	if (sig == SIGINT)
	{
		rl_on_new_line();
		rl_replace_line("", 0);
		printf("\n%s", get_shell_prompt(0));
		rl_redisplay();
	}
	g_signal = 0;
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
