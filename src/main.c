#include "minishell.h"

int		g_signal;

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

	all = (t_all *)xmalloc(sizeof(t_all) * 1);
	if (!all)
		return (NULL);
	all->line = NULL;
	all->tokens = NULL;
	all->tree = NULL;
	all->ex_tree = NULL;
	return (all);
}

void	shell_loop(void)
{
	t_all	*all;
	char	*prompt;
	char	*line;

	all = init_all();
	while (1)
	{
		prompt = get_shell_prompt(1);
		line = readline(prompt);
		all->line = line;
		if (ft_strlen(all->line) > 0)
			add_history(all->line);
		if (!all->line)
		{
			printf("exit\n");
			break ;
		}
		all->tokens = lexer((char *)all->line);
		all->tree = parser(all->tokens);
		check_fds(all->tree);
		all->ex_tree = semantic_analyzer(all->tree);
		executer(all->ex_tree);
		update_grobal_env();
		free_all_memory(all);
		free(prompt);
	}
}

int	main(int argc, char *argv[], char **env)
{
	(void)argc;
	(void)argv;
	grobal_env(SET, ft_strsdup(env));
	update_grobal_envlist();
	set_signal();
	shell_loop();
	return (0);
}
