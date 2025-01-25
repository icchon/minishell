/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:56:41 by kaisobe           #+#    #+#             */
/*   Updated: 2025/01/07 20:47:09 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IO_H
# define FT_IO_H

# include "ft_printf.h"
# include <stdio.h>
# include <unistd.h>

void	ft_putstr(char *s);
void	ft_print_arr(int *arr, int n);
char	*get_next_line(int fd);
void	ft_print_strs(char **strs);

#endif