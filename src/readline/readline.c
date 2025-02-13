/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:22:55 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/13 07:12:23 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

char	*get_shell_prompt(int exist_nl)
{
	char	*prompt;
	char	*prefix;

	prompt = ft_get_env("PWD", grobal_env(GET));
	prefix = "minishell :\x1b[32m";
	prompt = ft_strjoin(prefix, prompt);
	if (exist_nl)
		prompt = ft_strjoin_safe(prompt, "\x1b[39m \n % ", 1, 0);
	else
	{
		prompt = ft_strjoin_safe(prompt, "\x1b[39m \n", 1, 0);
	}
	return (prompt);
}

char	*get_readline(char *prompt)
{
	if (isatty(STDIN_FILENO) && isatty(STDERR_FILENO))
		return (readline(prompt));
	else
		return (get_next_line(STDIN_FILENO));
}
