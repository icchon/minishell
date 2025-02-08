#ifndef HEREDOC_H
#define HEREDOC_H

#include "ast.h"

char	*here_doc(char *delimited);
void	exec_heredoc(t_astnode *node);

#endif