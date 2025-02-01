/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:48:19 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/01 17:52:42 by kaisobe          ###   ########.fr       */
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
	char		*line;
	t_token		*tokens;
	t_astnode	*tree;

	(void)argc;
	(void)argv;
	line = NULL;
	grobal_env(SET, env);
	while (1)
	{
		line = readline("minishell > ");
		add_history(line);
		if (!line)
		{
			if (!line)
				dprintf(2, "line is null\n");
			free(line);
			continue ;
		}
		tokens = lexer((char *)line);
		tree = parser(tokens);
		executer(tree);
	}
	return (0);
}
