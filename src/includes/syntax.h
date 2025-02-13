/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:34:27 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/13 15:34:27 by kaisobe          ###   ########.fr       */
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
int			analyze_simple_command(t_token *tokens);

#endif