/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:25:24 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/10 15:25:25 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READLINE_H
# define READLINE_H

# include "libft.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <stdlib.h>

char	*get_shell_prompt(int exist_nl);

#endif