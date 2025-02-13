/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quate.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:34:45 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/13 07:01:27 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax.h"

void	init_quate_status(int status[ASCII_SIZE])
{
	status[NORMAL] = 1;
	status[IN_DOUBLE_QUOT] = 0;
	status[IN_SINGLE_QAOT] = 0;
}

void	update_quate_status(int status[ASCII_SIZE], t_quate_status type)
{
	status[type] = !status[type];
	if (type == NORMAL)
	{
		if (status[type])
		{
			init_quate_status(status);
		}
	}
	else if (type == IN_DOUBLE_QUOT || type == IN_SINGLE_QAOT)
	{
		if (!status[IN_DOUBLE_QUOT] && !status[IN_SINGLE_QAOT])
		{
			status[NORMAL] = 1;
		}
		else
		{
			status[NORMAL] = 0;
		}
	}
}

int	is_quate_closed(char *line)
{
	int	status[ASCII_SIZE];
	int	i;

	init_quate_status(status);
	i = 0;
	while (line[i])
	{
		if (line[i] == '\'' || line[i] == '"')
		{
			if (status[(int)line[i]] || status[(int)NORMAL])
			{
				update_quate_status(status, (t_quate_status)line[i]);
			}
		}
		i++;
	}
	return (status[NORMAL]);
}
