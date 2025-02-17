/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:25:24 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/13 07:12:30 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READLINE_H
# define READLINE_H

# include "libft.h"
# include "util.h"
# include <readline/history.h>
# include <readline/readline.h>

char	*get_shell_prompt(int exist_nl);
char	*get_readline(char *prompt);

#endif