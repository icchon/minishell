/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:24:36 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/13 15:24:37 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

int	is_valid_brackets(char *line)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '(')
		{
			cnt++;
		}
		if (line[i] == ')')
		{
			cnt--;
		}
		if (cnt < 0)
			return (0);
		i++;
	}
	return (cnt == 0);
}
