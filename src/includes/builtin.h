/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:33:26 by tkitago           #+#    #+#             */
/*   Updated: 2025/02/10 20:59:48 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "env.h"
# include "type.h"

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
int			check_export_equal(char *line, t_env **env_lst);
int			check_export_plus(char *line, char *check_plus, t_env **env_lst);
int			check_export_line(char *line, t_env **env_lst);
int			check_export_no_equal(char *line, t_env **env_lst);
int			append_env_noequal(t_env **env_lst, const char *name,
				const char *value);
#endif
