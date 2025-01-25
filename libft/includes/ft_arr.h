/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 23:38:01 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/23 23:51:09 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARR_H
# define FT_ARR_H

# include "ft_algo.h"
# include <stdlib.h>

int	*ft_dup_arr(int *arr, int n);
int	ft_indexof(int *arr, int n, int target);
int	ft_unique_arr(int *arr, int n);

#endif