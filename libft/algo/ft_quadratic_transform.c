/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quadratic_transform.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:20:53 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/23 16:26:52 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_algo.h"

int	ft_quadratic_transform(int a, int b, int c, int x)
{
	return (a * (x * x) + b * x + c);
}
