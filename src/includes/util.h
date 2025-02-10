/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:25:35 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/10 15:53:46 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include "env.h"
# include "type.h"

typedef struct stat	t_stat;

t_env				**grobal_envlist(int get_or_set, ...);
void				update_grobal_envlist(void);
void				update_grobal_env(void);
t_status			grobal_status(int get_or_set, ...);
char				**grobal_env(int get_or_set, ...);
char				*grobal_tmpfile(int get_or_set, ...);
void				update_grobal_envlist(void);
void				update_grobal_env(void);
int					contain_backslash(char *str);
int					is_executable(char *path);
int					is_directory(char *path);
void				free_all_grobal_vars(void);

#endif