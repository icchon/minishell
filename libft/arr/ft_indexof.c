/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indexof.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 23:41:38 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/23 23:41:48 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arr.h"

int	ft_indexof(int *arr, int n, int target)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (arr[i] == target)
			return (i);
		i++;
	}
	return (-1);
}
