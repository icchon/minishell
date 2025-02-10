/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:25:18 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/10 15:25:19 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

# include "ast.h"

char	*here_doc(char *delimited);
void	exec_heredoc(t_astnode *node);
void	put_error(size_t line, char *delimited);
int		check_delimited(t_strgen *strgen, char *str, char *delimited,
			size_t delimited_len);

#endif