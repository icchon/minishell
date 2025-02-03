/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:48:19 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/03 14:04:28 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_all_grobal_vars(void)
{
	if (!grobal_asttree(GET, NULL))
	{
		free_tokens(grobal_token(GET, NULL));
	}
	else
	{
		free_asttree(grobal_asttree(GET, NULL));
		free_ex_asttree(grobal_ex_asttree(GET, NULL));
	}
	if (grobal_tmpfile(GET, NULL))
	{
		unlink(grobal_tmpfile(GET, NULL));
		free(grobal_tmpfile(GET, NULL));
		grobal_tmpfile(SET, NULL);
	}
	free(grobal_bashinput(GET, NULL));
	return ;
}

void	free_all(t_astnode *tree, t_ex_astnode *ex_tree, t_token *tokens)
{
	if (!tree)
	{
		free_tokens(tokens);
	}
	else
	{
		free_asttree(tree);
		free_ex_asttree(ex_tree);
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
	char			*tmp;

	(void)argc;
	(void)argv;
	line = NULL;
	cnt = 0;
	grobal_env(SET, env);
	while (1)
	{
		line = readline("minishell > ");
		tmp = line;
		line = ft_strtrim(line, " \t\n\v\f\r");
		free(tmp);
		add_history(line);
		grobal_bashinput(SET, line);
		if (!line)
		{
			cnt++;
			if (!line)
				dprintf(2, "line is null\n");
			free(line);
			if (cnt > 10)
				break ;
		}
		tokens = lexer((char *)line);
		// print_tokens(tokens);
		tree = parser(tokens);
		check_fds(tree);
		ex_tree = semantic_analyzer(tree);
		// print_ex_tree(ex_tree);
		executer(ex_tree);
		free_all(tree, ex_tree, tokens);
	}
	return (0);
}
