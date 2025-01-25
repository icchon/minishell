/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sys.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 07:40:46 by kaisobe           #+#    #+#             */
/*   Updated: 2025/01/07 20:30:49 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SYS_H
# define FT_SYS_H

# include "ft_num.h"
# include "ft_str.h"
# include <fcntl.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

int		ft_create_file(char *filename);
char	*ft_get_env(char *key, char **env);
char	*ft_get_absolute_path(char *relative_path, char **env);
char	*ft_create_random_file(char *extension);
char	**ft_get_expanded_env(char *key, char sep, char **env);
char	**ft_get_expanded_path(char **env);
char	*ft_join_path(char *lower, char *upper);
int		ft_path_exist(char *path);

#endif