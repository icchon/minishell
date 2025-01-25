/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 10:41:46 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/22 14:38:35 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_f_arr(char *(*p[])(va_list x, t_options *ops))
{
	static int	is_initialized = 0;
	int			i;

	if (is_initialized)
		return ;
	i = 0;
	while (i < ASCII_SIZE)
	{
		p[i++] = create_nothing_arg_handler;
	}
	p['c'] = create_c_arg_handler;
	p['s'] = create_s_arg_handler;
	p['p'] = create_p_arg_handler;
	p['d'] = create_d_arg_handler;
	p['i'] = create_i_arg_handler;
	p['u'] = create_u_arg_handler;
	p['x'] = create_sx_arg_handler;
	p['X'] = create_lx_arg_handler;
	p['%'] = create_percent_arg_handler;
	is_initialized = 1;
	return ;
}
