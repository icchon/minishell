/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:32:40 by tkitago           #+#    #+#             */
/*   Updated: 2025/02/11 08:00:30 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

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
