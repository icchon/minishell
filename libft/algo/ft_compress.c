/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compress.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:38:14 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/23 23:49:46 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_algo.h"

int	ft_compress(int *arr, int n)
{
	int	*copied_arr;
	int	m;
	int	i;
	int	index;

	copied_arr = ft_dup_arr(arr, n);
	m = ft_unique_arr(copied_arr, n);
	i = 0;
	while (i < n)
	{
		index = ft_indexof(copied_arr, m, arr[i]);
		arr[i] = index;
		i++;
	}
	free(copied_arr);
	return (m);
}
