/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:23:48 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/10 15:54:25 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char *argv[], char **env)
{
	(void)argc;
	(void)argv;
	grobal_env(SET, ft_strsdup(env));
	update_grobal_envlist();
	set_signal();
	shell_loop();
	free_all_grobal_vars();
	rl_clear_history();
	return (grobal_status(GET));
}
