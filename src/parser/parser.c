/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:21:53 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/14 18:31:06 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

t_astnode	*parser(t_token *token)
{
	t_astnode	*ast_tree;

	ast_tree = parse_or_and(&token);
	return (ast_tree);
}
