/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:25:35 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/13 10:16:21 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include "env.h"
# include "type.h"

typedef struct stat	t_stat;

typedef enum e_quate_status
{
	IN_SINGLE_QAOT = '\'',
	IN_DOUBLE_QUOT = '\"',
	NORMAL = '\0',
}					t_quate_status;

t_env				**grobal_envlist(int get_or_set, ...);
void				update_grobal_envlist(void);
void				update_grobal_env(void);
t_status			grobal_status(int get_or_set, ...);
char				**grobal_env(int get_or_set, ...);
t_list				**grobal_tmpfile(int get_or_set, ...);
void				update_grobal_envlist(void);
void				update_grobal_env(void);
int					contain_backslash(char *str);
int					is_executable(char *path);
int					is_directory(char *path);
void				free_all_grobal_vars(void);
void				free_tmpfiles(void);
void				print_error(char *s, char *msg, int bash_flg);
void				init_quate_status(int status[ASCII_SIZE]);
void				update_quate_status(int status[ASCII_SIZE],
						t_quate_status type);
int					is_quate_closed(char *line);
char				**split_set(char const *s, const char *set);
char				**split_withsep(const char *str, const char *set);
char				**split_quatesafe(const char *str, const char *set,
						int broken);
int					count_words_withsep(const char *str, const char *set);
void				restore_ascii(char **strs);
void				restore2d_ascii(char *str);
void				keep_ascii(char *str, const char *set);

#endif