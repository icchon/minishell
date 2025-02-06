#include "minishell.h"

int			g_signal;

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
		all->line = ft_strtrim(line, " \t\n\v\f\r");
		if (g_signal == SIGINT)
		{
			grobal_status(SET, 130);
			g_signal = 0;
		}
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
}

static void	sig_int_handler(int sig)
{
	g_signal = sig;
	if (sig == SIGINT)
	{
		rl_on_new_line();
		rl_replace_line("", 0);
		write(STDOUT_FILENO, "\n", 1);
		printf("%s", get_shell_prompt(0));
		rl_redisplay();
	}
	return ;
}

int	main(int argc, char *argv[], char **env)
{
	(void)argc;
	(void)argv;
	grobal_env(SET, env);
	signal(SIGINT, sig_int_handler);
	shell_loop();
	return (0);
}
