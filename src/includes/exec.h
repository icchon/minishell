#ifndef EXEC_H
# define EXEC_H

# include "ast.h"
# include "type.h"
# include <sys/stat.h>
# include <sys/types.h>

typedef struct s_pids
{
	pid_t			pid;
	struct s_pids	*next;
}					t_pids;

pid_t				fork_and_exec_child(t_astnode *node, int old_pipes[2],
						int new_pipes[2]);
t_status			executer(t_ex_astnode *root);
t_pids				*new_pids(pid_t pid);
void				print_pids(t_pids *pids);
t_pids				*last_pid(t_pids *lst);
void				addback_pid(t_pids **lst, t_pids *newpid);
char				**create_args(t_astnode *node);
void				set_arginfo(t_astnode *node);
pid_t				*create_pids(int n);
int					**create_pipes(int n);
int					contain_backslash(char *str);
t_status			execute_one_builtin(t_astnode *root);
t_status			execute_fork_commands(t_list *cmds);
t_status			waitpids(t_list *cmds, pid_t *pids);
t_status			check_fds(t_redirect *redirect);

#endif