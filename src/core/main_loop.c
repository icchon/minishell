/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:39:07 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/14 14:03:50 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

extern int	g_signal;

static void	init_loop(t_all *all)
{
	free_all_prop(all);
	update_grobal_env();
	free_all_prop(all);
	update_grobal_env();
	all->prompt = get_shell_prompt(1);
	rl_on_new_line();
	rl_replace_line("", 0);
	all->line = ft_strtrim_safe(get_readline(all->prompt), " \n\t");
	return ;
}

static void	main_process(t_all *all)
{
	if (ft_strlen(all->line) > 0)
		add_history(all->line);
	all->tokens = lexer((char *)all->line);
	if (!syntax_analyzer(all->tokens))
	{
		ft_dprintf(STDERR_FILENO, "bash: syntax error\n");
		grobal_status(SET, 126);
		return ;
	}
	all->tree = parser(all->tokens);
	all->ex_tree = semantic_analyzer(all->tree);
	if (g_signal != 0)
	{
		grobal_status(SET, g_signal + 128);
	}
	signal(SIGINT, sig_handler_while_child);
	signal(SIGQUIT, sig_handler_while_child);
	grobal_status(SET, executer(all->ex_tree));
	if (g_signal != 0)
	{
		grobal_status(SET, g_signal + 128);
	}
	g_signal = 0;
	signal(SIGINT, sig_int_handler);
	signal(SIGQUIT, SIG_IGN);
}

void	shell_loop(void)
{
	t_all	*all;

	all = init_all();
	while (1)
	{
		init_loop(all);
		if (!all->line)
		{
			ft_dprintf(STDERR_FILENO, "exit\n");
			break ;
		}
		if (!is_valid_input(all->line))
		{
			ft_dprintf(STDERR_FILENO, "bash: syntax error\n");
			grobal_status(SET, 126);
			continue ;
		}
		main_process(all);
	}
	free_all(all);
}
