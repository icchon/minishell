/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_simple_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:52:18 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/13 15:52:37 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

pid_t	execute_simple_command(t_astnode *root, int old_pipes[2],
		int new_pipes[2])
{
	t_astnode_type	type;
	pid_t			pid;

	if (!root)
		return (-1);
	type = root->type;
	if (type != ASTND_CMD)
		return (-1);
	expander(root);
	set_arginfo(root);
	pid = fork_and_exec_child(root, old_pipes, new_pipes);
	return (pid);
}
