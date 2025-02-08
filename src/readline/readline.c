#include "minishell.h"

char	*get_shell_prompt(int exist_nl)
{
	char	*prompt;
	char	*prefix;

	// prompt = getenv("PWD");
	update_grobal_env();
	prompt = ft_get_env("PWD", grobal_env(GET));
	prefix = "minishell :\x1b[32m";
	prompt = ft_strjoin(prefix, prompt);
	if (exist_nl)
		prompt = ft_strjoin_safe(prompt, "\x1b[39m \n % ", 1, 0);
	else
	{
		prompt = ft_strjoin_safe(prompt, "\x1b[39m \n", 1, 0);
	}
	return (prompt);
}

char	*trim_space(char *line)
{
	char	*tmp;

	tmp = line;
	line = ft_strtrim(line, " \t\n\v\f\r");
	free(tmp);
	return (line);
}
