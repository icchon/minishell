/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unique_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 23:39:05 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/23 23:50:46 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arr.h"

int	ft_unique_arr(int *arr, int n)
{
	int	cnt;
	int	i;
	int	j;
	int	*copied_arr;

	j = 1;
	copied_arr = ft_dup_arr(arr, n);
	ft_sort(copied_arr, n, 0);
	cnt = 1;
	i = 0;
	arr[0] = copied_arr[0];
	while (i < n - 1)
	{
		if (copied_arr[i] != copied_arr[i + 1])
		{
			arr[j] = copied_arr[i + 1];
			j++;
			cnt++;
		}
		i++;
	}
	free(copied_arr);
	return (cnt);
}
