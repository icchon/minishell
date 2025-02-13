/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:24:36 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/14 07:23:31 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

int	is_valid_brackets(char *line)
{
	int	cnt;
	int	i;

	keep_ascii(line, "()");
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
	restore2d_ascii(line);
	return (cnt == 0);
}
