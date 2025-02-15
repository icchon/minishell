/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:34:27 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/15 16:46:12 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYNTAX_H
# define SYNTAX_H

# include "token.h"
# include "type.h"
# include "util.h"

typedef int	*(*t_analyze_f)(t_token *token);

int			syntax_analyzer(t_token *tokens);
int			is_valid_brackets(char *line);
int			is_valid_input(char *line);
int			analyze_pipe(t_token *token);
int			analyze_logical_op(t_token *token);
int			analyze_heredoc(t_token *token);
int			analyze_redirect(t_token *token);
int			analyze_bracket_pairs(t_token *tokens);
int			analyze_simple_command(t_token *tokens);
t_token		*get_kth_braleft_token(t_token *tokens, int k);
int			count_brackets(t_token *tokens);
int			analyze_bracket_connections(t_token *tokens);

#endif