#ifndef EXPANDER_H
#define EXPANDER_H

#include "ast.h"

void				expander(t_astnode *node);
char				*replace_env_vars(char *str, char **env);
char				*replace_env_vars_quate(char *str, char **env);

#endif