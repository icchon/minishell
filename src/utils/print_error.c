/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 07:26:27 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/11 07:27:01 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void	print_error(char *s, char *msg, int bash_flg)
{
	if (bash_flg)
		ft_putstr_fd("bash: ", 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	return ;
}
