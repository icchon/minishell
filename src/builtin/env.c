/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:32:40 by tkitago           #+#    #+#             */
/*   Updated: 2025/02/10 20:32:41 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	builtin_env(t_env *envp)
{
	while (envp)
	{
		if (ft_strchr(envp->line, '='))
			ft_putendl_fd(envp->line, STDOUT_FILENO);
		envp = envp->next;
	}
	return (EXIT_SUCCESS);
}
