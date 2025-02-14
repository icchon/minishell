/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_all_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:11:13 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/14 21:52:31 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_all_prop(t_all *all)
{
	free_asttree(all->tree);
	all->tree = NULL;
	free_ex_asttree(all->ex_tree);
	all->ex_tree = NULL;
	free_tmpfiles();
	free(all->line);
	all->line = NULL;
	free(all->prompt);
	all->prompt = NULL;
	return ;
}

void	free_all(t_all *all)
{
	free_all_prop(all);
	free(all);
	return ;
}

t_all	*init_all(void)
{
	t_all	*all;

	all = (t_all *)xmalloc(sizeof(t_all) * 1);
	if (!all)
		return (NULL);
	all->line = NULL;
	all->tokens = NULL;
	all->tree = NULL;
	all->ex_tree = NULL;
	all->prompt = NULL;
	return (all);
}
