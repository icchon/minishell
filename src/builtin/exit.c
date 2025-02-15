/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:32:44 by tkitago           #+#    #+#             */
/*   Updated: 2025/02/15 09:56:52 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static int	get_exit_code(char *av)
{
	int	exit_code;
	int	tmp_exit_code;

	if (!ft_islong(av))
	{
		ft_dprintf(STDERR_FILENO, "exit: %s: numeric argument required\n", av);
		exit(2);
	}
	exit_code = ft_atoi(av);
	tmp_exit_code = exit_code;
	if (exit_code < 0)
		exit_code &= 0xFF;
	else
	{
		while (tmp_exit_code > 256)
		{
			exit_code = tmp_exit_code % 256;
			tmp_exit_code /= 256;
		}
	}
	return (exit_code);
}

int	builtin_exit(int ac, char *av[], int last_status)
{
	if (ac == 1)
	{
		ft_putendl_fd("exit", STDERR_FILENO);
		exit(last_status);
	}
	else if (ac == 2)
	{
		ft_putendl_fd("exit", STDERR_FILENO);
		exit(get_exit_code(av[1]));
	}
	else
	{
		ft_putendl_fd("exit: too many arguments", STDERR_FILENO);
		return (1);
	}
	return (0);
}
// call a couple of time of exit() is undefined