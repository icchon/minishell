/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 06:40:20 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/22 14:37:46 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*(*g_create_funcs[(ASCII_SIZE)])(va_list x, t_options *o);

static t_list	*create_ordinary(const char *fmt, int *i, t_list **head)
{
	char		*input_str;
	t_options	*ops;
	t_block		*block;
	t_list		*node;

	input_str = ft_substr(&fmt[*i], 0, ft_calc_next_chr((char *)&fmt[*i], '%'));
	if (input_str == NULL)
		return (NULL);
	ops = create_new_options();
	if (ops == NULL)
		return (NULL);
	block = create_block(ops, input_str);
	if (block == NULL)
		return (NULL);
	node = ft_lstnew(block);
	if (node == NULL)
		return (NULL);
	ft_lstadd_back(head, node);
	*i += ft_strlen(input_str);
	free(input_str);
	return (node);
}

static t_list	*create_variable(const char *fmt, int *i, t_list **head,
		va_list ap)
{
	t_options	*ops;
	t_block		*block;
	char		*input_str;
	t_list		*node;

	(*i)++;
	ops = create_options_obj((char *)&fmt[*i], ap);
	if (ops == NULL)
		return (NULL);
	input_str = g_create_funcs[(unsigned int)(ops->spec)](ap, ops);
	if (input_str == NULL)
		return (NULL);
	block = create_block(ops, input_str);
	node = ft_lstnew(block);
	if (node == NULL || block == NULL)
		return (NULL);
	ft_lstadd_back(head, node);
	while (!ft_contain(SPECIFER_SET, fmt[*i]))
	{
		if (!fmt[*i])
			return (node);
		(*i)++;
	}
	return ((*i)++, free(input_str), node);
}

static t_list	*create_all_blocks(const char *fmt, va_list ap)
{
	t_list	*head;
	t_list	*node;
	int		i;

	i = 0;
	head = NULL;
	init_f_arr(g_create_funcs);
	while (fmt[i])
	{
		if (fmt[i] == '%')
			node = create_variable(fmt, &i, &head, ap);
		else
			node = create_ordinary(fmt, &i, &head);
		if (node == NULL)
		{
			return (head);
		}
	}
	return (head);
}

int	ft_dprintf(int fd, const char *fmt, ...)
{
	va_list	ap;
	int		printed_len;
	t_list	*lst;
	t_list	*node;
	t_block	*block;

	va_start(ap, fmt);
	lst = create_all_blocks(fmt, ap);
	if (lst == NULL)
		return (-1);
	va_end(ap);
	printed_len = 0;
	node = lst;
	while (node != NULL)
	{
		block = (t_block *)(node->content);
		if (write(fd, block->output_str, block->length
				+ (block->ops->spec == CHAR && block->length == 0)) < 0)
			return (free_all(lst), -1);
		printed_len += block->length + (block->ops->spec == CHAR
				&& block->length == 0);
		node = node->next;
	}
	free_all(lst);
	return (printed_len);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		printed_len;
	t_list	*lst;
	t_list	*node;
	t_block	*block;

	va_start(ap, fmt);
	lst = create_all_blocks(fmt, ap);
	if (lst == NULL)
		return (-1);
	va_end(ap);
	printed_len = 0;
	node = lst;
	while (node != NULL)
	{
		block = (t_block *)(node->content);
		if (write(1, block->output_str, block->length
				+ (block->ops->spec == CHAR && block->length == 0)) < 0)
			return (free_all(lst), -1);
		printed_len += block->length + (block->ops->spec == CHAR
				&& block->length == 0);
		node = node->next;
	}
	free_all(lst);
	return (printed_len);
}
