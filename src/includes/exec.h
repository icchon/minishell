#ifndef EXEC_H
#define EXEC_H

#include "ast.h"
#include "type.h"

typedef struct s_pids
{
	pid_t			pid;
	struct s_pids	*next;
}					t_pids;


void				exec_heredoc(t_astnode *node);
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
int					is_directory(char *str);
int					is_command(char *str);


#endif