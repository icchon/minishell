/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 22:22:02 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/22 16:27:19 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "ft_is.h"
# include "ft_lst.h"
# include "ft_mem.h"
# include "ft_num.h"
# include "ft_str.h"
# include "ft_util.h"
# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef ASCII_SIZE
#  define ASCII_SIZE 128
# endif

# ifndef SPECIFER_SET
#  define SPECIFER_SET "cspdiuxX%"
# endif

# ifndef TEST_BUFF
#  define TEST_BUFF 1000
# endif

# ifndef FLG_SET
#  define FLG_SET "-0+- #"
# endif

typedef enum e_flg
{
	PAD_LEFT = '-',
	PAD_ZERO = '0',
	SIGNED = '+',
	SIGNED_SPACE = ' ',
	HEX_PREFIX = '#',
	NONE_FLG = 0,
}				t_flg;

// cspdiuxX%
typedef enum e_specifer
{
	CHAR = 'c',
	STR = 's',
	POINTER = 'p',
	DEC = 'd',
	INT = 'i',
	U_INT = 'u',
	S_HEX = 'x',
	L_HEX = 'X',
	PERCENT = 'p',
	NONE_SPEC = 0,
}				t_specifer;

typedef struct s_options
{
	t_flg		flgs[ASCII_SIZE];
	int			width;
	int			prec;
	t_specifer	spec;
}				t_options;

typedef struct s_block
{
	t_options	*ops;
	char		*output_str;
	int			length;
}				t_block;

int				ft_printf(const char *fmt, ...);
int				ft_dprintf(int fd, const char *fmt, ...);
int				calc_output_length(t_options *ops, char *input_str);

char			*create_c_arg_handler(va_list ap, t_options *ops);
char			*create_d_arg_handler(va_list ap, t_options *ops);
char			*create_i_arg_handler(va_list ap, t_options *ops);
char			*create_p_arg_handler(va_list ap, t_options *ops);
char			*create_s_arg_handler(va_list ap, t_options *ops);
char			*create_u_arg_handler(va_list ap, t_options *ops);
char			*create_sx_arg_handler(va_list ap, t_options *ops);
char			*create_lx_arg_handler(va_list ap, t_options *ops);
char			*create_percent_arg_handler(va_list ap, t_options *ops);
char			*create_nothing_arg_handler(va_list ap, t_options *ops);
char			*get_prefix(t_options *ops, char *input_str);
char			*pad_and_move_to_edge(const char *src, int len, char pad,
					int is_right_edge);
char			*get_prefix(t_options *ops, char *input_str);
char			*create_output_str(t_options *ops, char *input_str,
					int output_length, char *prefix);

t_options		*parse_command(char *command, va_list ap);
t_options		*create_options_obj(char *start_of_block, va_list ap);
t_options		*create_new_options(void);

void			print_options_for_debug(t_options *ops);
void			update_options(t_options *ops);
void			init_f_arr(char *(*p[])(va_list x, t_options *o));
void			move_flg_to_left(char *output_str);
void			move_hex_prefix_to_left(char *output_str, char *prefix);

t_block			*create_block(t_options *ops, char *input_str);
void			free_all(t_list *lst);

#endif