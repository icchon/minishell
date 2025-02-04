#include "minishell.h"

char	*get_shell_prompt(void)
{
	char	*prompt;
	char	*prefix;

	prompt = getenv("PWD");
	prefix = "minishell :\x1b[32m";
	prompt = ft_strjoin(prefix, prompt);
	prompt = ft_strjoin_safe(prompt, "\x1b[39m \n % ", 1, 0);
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
