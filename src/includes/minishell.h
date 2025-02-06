#ifndef MINISHELL_H
# define MINISHELL_H

# include "ast.h"
# include "builtin.h"
# include "env.h"
# include "exec.h"
# include "expander.h"
# include "libft.h"
# include "readline.h"
# include "signals.h"
# include "token.h"
# include "type.h"
# include "util.h"

# define INPUT 0
# define OUTPUT 1
# define READ 0
# define WRITE 1
# define GET 0
# define SET 1
# define CHILD_PID 0
# define PARENT_PID 1
# define BUFFER_SIZE 1000
# define ASCII_SIZE 128

extern int			g_signal;

typedef struct s_all
{
	char			*line;
	char			**env;
	t_token			*tokens;
	t_astnode		*tree;
	t_ex_astnode	*ex_tree;
}					t_all;

void				shell_loop(void);
t_all				*init_all(void);
void				free_all_memory(t_all *all);

#endif