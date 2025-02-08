#include "readline.h"

char	*get_shell_prompt(int exist_nl)
{
	char	*prompt;
	char	*prefix;

	prompt = getenv("PWD");
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
