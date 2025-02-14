/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:25:26 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/14 19:02:44 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# include "libft.h"
# include "readline.h"
# include <signal.h>

extern int					g_signal;

typedef struct sigaction	t_sigaction;

void						sig_int_handler(int sig);
void						sig_quit_handler(int sig);
void						sig_handler_while_child(int sig);
void						set_signal_handlers(__sighandler_t int_handler,
								__sighandler_t quit_handler);

#endif