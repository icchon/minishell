#ifndef ENV_H
# define ENV_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_env
{
	char			*value;
	struct s_env	*next;
}					t_env;

t_env				*new_env_node(const char *env);
t_env				*create_env_list(char **envp);
void				print_env_list(t_env *env_list);
void				free_env_list(t_env *env_list);
int					env_size(t_env *envlist);

#endif