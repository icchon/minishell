#ifndef UTIL_H
# define UTIL_H

# include "env.h"
# include "type.h"

t_env		**grobal_envlist(int get_or_set, ...);
void		update_grobal_envlist(void);
void		update_grobal_env(void);
t_status	grobal_status(int get_or_set, ...);
char		**grobal_env(int get_or_set, ...);
char		*grobal_tmpfile(int get_or_set, ...);
void		update_grobal_envlist(void);
void		update_grobal_env(void);

#endif