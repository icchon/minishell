#include "minishell.h"

int			g_signal;

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

static int	is_interactive(void)
{
	return (isatty(STDIN_FILENO) && isatty(STDERR_FILENO));
}

void	shell_loop(void)
{
	t_all		*all;
	t_status	status;

	all = init_all();
	while (1)
	{
		all->prompt = get_shell_prompt(1);
		if (is_interactive())
		{
			all->line = readline(all->prompt);
		}
		else
		{
			all->line = get_next_line(STDIN_FILENO);
		}
		if (ft_strlen(all->line) > 0)
			add_history(all->line);
		if (!all->line)
		{
			printf("exit\n");
			break ;
		}
		all->tokens = lexer((char *)all->line);
		// print_tokens(all->tokens);
		all->tree = parser(all->tokens);
		// print_tree(all->tree);
		all->ex_tree = semantic_analyzer(all->tree);
		status = executer(all->ex_tree);
		grobal_status(SET, status);
		// print_ex_tree(all->ex_tree);
		update_grobal_env();
		free_all_prop(all);
	}
	free_all(all);
}

int	main(int argc, char *argv[], char **env)
{
	(void)argc;
	(void)argv;
	grobal_env(SET, ft_strsdup(env));
	update_grobal_envlist();
	set_signal();
	shell_loop();
	ft_2darraydel(grobal_env(GET));
	rl_clear_history();
	return (grobal_status(GET));
}
