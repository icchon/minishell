/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:25:13 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/13 15:52:35 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "ast.h"
# include "builtin.h"
# include "expander.h"
# include "type.h"

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
t_status			execute_single_builtin(t_astnode *root);
t_status			execute_fork_commands(t_list *cmds);
pid_t				execute_simple_command(t_astnode *root, int old_pipes[2],
						int new_pipes[2]);
t_status			waitpids(int len, pid_t *pids);
int					check_fds(t_redirect *redirect);
void				handle_io(t_token *redirect);

#endif