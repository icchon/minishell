/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:25:18 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/15 15:09:29 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

# include "ast.h"
# include "expander.h"
# include "util.h"

# define HEREDOC_BUFFERSIZE 10000

char	*here_doc(char *delimited);
void	child_heredoc(int pp[2], char *limiter);
void	exec_heredoc(t_astnode *node);

#endif