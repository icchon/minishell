/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:39:07 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/13 16:17:04 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

static void	init_loop(t_all *all)
{
	free_all_prop(all);
	update_grobal_env();
	free_all_prop(all);
	update_grobal_env();
	all->prompt = get_shell_prompt(1);
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
		ft_putstr_fd("bash: syntax error\n", STDERR_FILENO);
		grobal_status(SET, 126);
		return ;
	}
	all->tree = parser(all->tokens);
	all->ex_tree = semantic_analyzer(all->tree);
	grobal_status(SET, executer(all->ex_tree));
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
			ft_putstr_fd("exit\n", STDERR_FILENO);
			break ;
		}
		if (!is_valid_input(all->line))
		{
			printf("bash: syntax error\n");
			grobal_status(SET, 126);
			continue ;
		}
		main_process(all);
	}
	free_all(all);
}
