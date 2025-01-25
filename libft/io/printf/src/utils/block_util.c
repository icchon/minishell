/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 10:37:11 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/22 14:38:32 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_block	*create_block(t_options *ops, char *input_str)
{
	t_block	*block;
	int		output_length;

	block = (t_block *)malloc(sizeof(t_block) * 1);
	if (block == NULL)
		return (NULL);
	block->ops = ops;
	output_length = calc_output_length(ops, input_str);
	block->length = output_length;
	block->output_str = create_output_str(ops, input_str, output_length,
			get_prefix(ops, input_str));
	if (block->output_str == NULL)
		return (NULL);
	return (block);
}

void	free_all(t_list *lst)
{
	t_block	*block;
	t_list	*pre;

	while (lst != NULL)
	{
		block = (t_block *)lst->content;
		if (block == NULL)
			return ;
		if (block->output_str != NULL)
			free(block->output_str);
		pre = lst;
		lst = lst->next;
		if (block->ops != NULL)
			free(block->ops);
		free(block);
		free(pre);
	}
	return ;
}
