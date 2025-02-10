#ifndef EXPANDER_H
# define EXPANDER_H

# include "ast.h"

void	expander(t_astnode *node);
char	*replace_env_vars(char *str);
char	*expand_word(char *str);

#endif