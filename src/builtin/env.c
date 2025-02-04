/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:18:27 by tkitago           #+#    #+#             */
/*   Updated: 2025/02/03 07:33:01 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	builtin_env(char **envp)
{
	while (*envp)
	{
		ft_putendl_fd(*envp, STDOUT_FILENO);
		envp++;
	}
	return (EXIT_SUCCESS);
}

// int	main(int ac, char *av[], char **envp)
// {
// 	(void)ac;
// 	(void)av;
// 	if (setenv("_", "/usr/bin/env", 1) != 0)
// 	{
// 		perror("setenv");
// 		return (EXIT_FAILURE);
// 	}
// 	builtin_env(envp);
// }

// https://pubs.opengroup.org/onlinepubs/9699919799/utilities/env.html
// setenv必要か、
// unset の対応