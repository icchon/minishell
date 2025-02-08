#ifndef ENV_H
# define ENV_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_env
{
	char			*value;
	char			*key;
	char			*line;
	struct s_env	*next;
}					t_env;

char	*extract_key(const char *line);
char	*extract_value(const char *line);
char	*concat_key_value(const char *key, const char *value);
t_env				*new_env_node(const char *env);
t_env				*create_env_list(char **envp);
void				print_env_list(t_env *env_list);
void				free_env_list(t_env *env_list);
int					env_size(t_env *envlist);
t_env				*last_env(t_env *env_list);
void				addback_env(t_env **env_list, t_env *new_env);
void free_env_node(t_env *env_node);

#endif