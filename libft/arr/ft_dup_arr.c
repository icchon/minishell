/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 23:38:41 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/23 23:38:57 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arr.h"

int	*ft_dup_arr(int *arr, int n)
{
	int	*copied_arr;
	int	i;

	copied_arr = (int *)malloc(sizeof(int) * n);
	i = 0;
	while (i < n)
	{
		copied_arr[i] = arr[i];
		i++;
	}
	return (copied_arr);
}
