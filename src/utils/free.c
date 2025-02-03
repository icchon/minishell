/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 13:44:16 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/03 11:26:59 by kaisobe          ###   ########.fr       */
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
