#include "minishell.h"

void	free_all_memory(t_all *all)
{
	if (!all->tree)
	{
		free_tokens(all->tokens);
	}
	else
	{
		free_asttree(all->tree);
		free_ex_asttree(all->ex_tree);
	}
	if (grobal_tmpfile(GET))
	{
		unlink(grobal_tmpfile(GET));
		free(grobal_tmpfile(GET));
		grobal_tmpfile(SET, NULL);
	}
	free(all->line);
	return ;
}

t_all	*init_all(void)
{
	t_all	*all;

	all = (t_all *)malloc(sizeof(t_all) * 1);
	if (!all)
		return (NULL);
	all->line = NULL;
	all->tokens = NULL;
	all->tree = NULL;
	all->ex_tree = NULL;
	return (all);
}

int	main(int argc, char *argv[], char **env)
{
	t_all	*all;
	char	*prompt;
	char	*line;

	(void)argc;
	(void)argv;
	all = init_all();
	grobal_env(SET, env);
	while (1)
	{
		prompt = get_shell_prompt();
		line = readline(prompt);
		all->line = ft_strtrim(line, " \t\n\v\f\r");
		add_history(all->line);
		if (!all->line)
			break ;
		all->tokens = lexer((char *)all->line);

		all->tree = parser(all->tokens);

		check_fds(all->tree);
		all->ex_tree = semantic_analyzer(all->tree);
		executer(all->ex_tree);
		free_all_memory(all);
		free(prompt);
		free(line);
	}
	return (0);
}
