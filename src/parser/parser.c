/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:21:53 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/10 15:22:10 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_astnode	*parser(t_token *token)
{
	t_astnode	*ast_tree;

	ast_tree = parse_or_and(&token);
	exec_heredoc(ast_tree);
	return (ast_tree);
}
