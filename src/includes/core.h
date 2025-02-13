/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:11:58 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/13 16:16:10 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# include "ast.h"
# include "exec.h"
# include "readline.h"
# include "syntax.h"
# include "token.h"
# include "type.h"

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
void				free_all(t_all *all);
void				free_all_prop(t_all *all);

#endif