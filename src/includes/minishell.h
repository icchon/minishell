/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:25:20 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/11 07:28:08 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "ast.h"
# include "builtin.h"
# include "env.h"
# include "exec.h"
# include "expander.h"
# include "heredoc.h"
# include "libft.h"
# include "readline.h"
# include "signals.h"
# include "token.h"
# include "type.h"
# include "util.h"

typedef struct s_all
{
	char			*line;
	char			*prompt;
	char			**env;
	t_token			*tokens;
	t_astnode		*tree;
	t_ex_astnode	*ex_tree;
}					t_all;

void				shell_loop(void);
t_all				*init_all(void);
void				free_all_memory(t_all *all);

#endif