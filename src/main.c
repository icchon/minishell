/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:48:19 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/03 08:25:28 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	end(void)
{
	if (!grobal_asttree(GET, NULL))
	{
		free_tokens(grobal_token(GET, NULL));
	}
	else
	{
		free_asttree(grobal_asttree(GET, NULL));
	}
	if (grobal_tmpfile(GET, NULL))
	{
		unlink(grobal_tmpfile(GET, NULL));
		free(grobal_tmpfile(GET, NULL));
	}
	free(grobal_bashinput(GET, NULL));
	return ;
}

int	main(int argc, char *argv[], char **env)
{
	char			*line;
	t_token			*tokens;
	t_astnode		*tree;
	t_ex_astnode	*ex_tree;
	int				cnt;

	(void)argc;
	(void)argv;
	line = NULL;
	cnt = 0;
	grobal_env(SET, env);
	while (1)
	{
		line = readline("minishell > ");
		add_history(line);
		if (!line)
		{
			cnt++;
			if (!line)
				dprintf(2, "line is null\n");
			free(line);
			if (cnt > 20)
			{
				dprintf(2, "infinity roop occured\n");
				break ;
			}
			continue ;
		}
		tokens = lexer((char *)line);
		// print_tokens(tokens);
		tree = parser(tokens);
		check_fds(tree);
		//print_tree(tree);
		ex_tree = semantic_analyzer(tree);
		//print_ex_tree(ex_tree);
		executer(ex_tree);
	}
	return (0);
}
