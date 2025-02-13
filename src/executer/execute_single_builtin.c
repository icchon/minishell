/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_single_builtin.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:50:09 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/13 15:50:23 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

t_status	execute_single_builtin(t_astnode *root)
{
	t_status	status;
	int			stdin;
	int			stdout;

	expander(root);
	set_arginfo(root);
	if (!check_fds(root->redirects))
		return (EXIT_FAILURE);
	stdin = dup(STDIN_FILENO);
	stdout = dup(STDOUT_FILENO);
	handle_io(root->redirects);
	status = builtin(root->arg_strs);
	dup2(stdin, STDIN_FILENO);
	dup2(stdout, STDOUT_FILENO);
	close(stdin);
	close(stdout);
	return (status);
}
