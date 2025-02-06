#ifndef READLINE_H
# define READLINE_H

# include "libft.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <stdlib.h>

char	*trim_space(char *line);
char	*get_shell_prompt(int exist_nl);

#endif