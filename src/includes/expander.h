/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:25:16 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/11 07:42:56 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include "ast.h"
# include "type.h"
# include "util.h"

void	expander(t_astnode *node);
char	*replace_env_vars(char *str);
char	*expand_word(char *str);
int		is_single_quate(char *str);
int		is_double_quate(char *str);
char	*trim_quate(char *str);
t_token	*token_variable_split(t_token **token);

#endif