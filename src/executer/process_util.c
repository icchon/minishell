/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:03:20 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/04 15:03:31 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_directory(char *str)
{
	if (ft_strchr(str, '/'))
		return (1);
	return (0);
}

int	is_command(char *str)
{
	return (!is_directory(str));
}
