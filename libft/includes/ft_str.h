/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 14:21:07 by kaisobe           #+#    #+#             */
/*   Updated: 2025/01/24 09:21:15 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STR_H
# define FT_STR_H

# define BUFFER_SIZE 100000

# include "ft_is.h"
# include "ft_str.h"
# include "ft_util.h"
# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_atoi(const char *nptr);
long	ft_atol(const char *nptr);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
size_t	ft_strslen(const char **strs);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_contain(char *str, char c);
int		ft_calc_next_chr(char *str, char c);
char	*ft_chr_to_str(char c);
int		ft_calc_next_str(char *src, char *set);
char	*ft_create_chain(char c, int n);
void	ft_chrset(char *s, char c, int n);
int		ft_atoi_base(char *str, char *base);
char	*ft_strjoin_safe(char *s1, char *s2, int is_free1, int is_free2);
void	free_strs(char **strs);

#endif