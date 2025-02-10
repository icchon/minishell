#ifndef BUILTIN_H
# define BUILTIN_H

# include "env.h"
# include "type.h"
# include "util.h"

int			builtin_env(t_env *envp);
int			builtin_pwd(char **envp);
int			builtin_unset(int ac, char *av[], t_env **env);
int			builtin_echo(int ac, char *av[]);
int			builtin_exit(int argc, char *argv[], int last_status);
t_status	builtin(char *av[]);
int			is_builtin(char *cmd);
int			builtin_cd(int ac, char *av[], t_env **env_lst);
int			builtin_export(int ac, char *av[], t_env **env_lst);
int			util_setenv(t_env **env_lst, const char *name, const char *value,
				int append_flg);

#endif