/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:39:07 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/10 15:39:41 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_all_prop(t_all *all)
{
	free_asttree(all->tree);
	all->tree = NULL;
	free_ex_asttree(all->ex_tree);
	all->ex_tree = NULL;
	if (grobal_tmpfile(GET))
	{
		unlink(grobal_tmpfile(GET));
		free(grobal_tmpfile(GET));
		grobal_tmpfile(SET, NULL);
	}
	free(all->line);
	all->line = NULL;
	free(all->prompt);
	all->prompt = NULL;
	return ;
}

void	free_all(t_all *all)
{
	free_all_prop(all);
	free(all);
	return ;
}

t_all	*init_all(void)
{
	t_all	*all;

	all = (t_all *)xmalloc(sizeof(t_all) * 1);
	if (!all)
		return (NULL);
	all->line = NULL;
	all->tokens = NULL;
	all->tree = NULL;
	all->ex_tree = NULL;
	all->prompt = NULL;
	return (all);
}

static char	*get_readline(char *prompt)
{
	if (isatty(STDIN_FILENO) && isatty(STDERR_FILENO))
		return (readline(prompt));
	else
		return (get_next_line(STDIN_FILENO));
}

void	shell_loop(void)
{
	t_all		*all;
	t_status	status;

	all = init_all();
	while (1)
	{
		all->prompt = get_shell_prompt(1);
		all->line = get_readline(all->prompt);
		if (ft_strlen(all->line) > 0)
			add_history(all->line);
		if (!all->line)
		{
			printf("exit\n");
			break ;
		}
		all->tokens = lexer((char *)all->line);
		all->tree = parser(all->tokens);
		all->ex_tree = semantic_analyzer(all->tree);
		status = executer(all->ex_tree);
		grobal_status(SET, status);
		update_grobal_env();
		free_all_prop(all);
	}
	free_all(all);
}
