/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:44:37 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/23 23:49:02 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ALGO_H
# define FT_ALGO_H

# include "ft_arr.h"
# include <limits.h>
# include <stdlib.h>

int		ft_compress(int *arr, int n);
void	ft_sort(int *arr, int n, int reversed);
int		ft_quadratic_transform(int a, int b, int c, int x);

#endif