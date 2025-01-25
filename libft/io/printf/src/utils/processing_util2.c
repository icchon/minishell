/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_util2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 10:40:37 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/22 14:38:50 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	calc_output_length(t_options *ops, char *input_str)
{
	int	len;

	if (ops->spec == STR)
		len = ft_max(2, ft_min(2, ops->prec, ft_strlen(input_str))
				* (ops->prec != -1) + ft_strlen(input_str) * (ops->prec == -1),
				ops->width);
	else if (ft_ismatch(ops->spec, 5, DEC, INT, U_INT, S_HEX, L_HEX))
	{
		if (ft_ismatch(ops->spec, 3, INT, DEC, U_INT))
			len = ft_max(2, ft_max(2, ops->prec, ft_strlen(input_str)
						- (input_str[0] == '-')) + (input_str[0] == '-')
					+ ((ops->flgs[SIGNED] && input_str[0] != '-')
						|| (ops->flgs[SIGNED_SPACE] && input_str[0] != '-')),
					ops->width);
		else
			len = ft_max(2, ft_max(2, ops->prec, ft_strlen(input_str))
					+ ft_strlen("0x") * (ops->flgs[HEX_PREFIX]
						&& !ft_ischain(input_str, '0')), ops->width);
		if (ops->prec == 0 && ft_ischain(input_str, '0'))
			len = ops->width;
	}
	else
		len = ft_max(2, ops->width, ft_strlen(input_str));
	return (len);
}

void	apply_offset(t_options *ops, char *str)
{
	if (ops->flgs[PAD_ZERO] && ft_ismatch(ops->spec, 2, DEC, INT))
		move_flg_to_left(str);
	if (ops->flgs[PAD_ZERO] && ft_ismatch(ops->spec, 2, S_HEX, POINTER))
		move_hex_prefix_to_left(str, "0x");
	if (ops->flgs[PAD_ZERO] && ops->spec == L_HEX)
		move_hex_prefix_to_left(str, "0X");
	return ;
}

char	*create_output_str(t_options *ops, char *input_str, int len, char *pref)
{
	char	*out;
	char	*tmp;
	int		is_shift;
	char	pad;

	pad = ' ';
	is_shift = (input_str[0] == '-' && !ft_ismatch(ops->spec, 2, NONE_SPEC,
				STR));
	input_str += is_shift;
	if (ops->flgs[PAD_ZERO])
		pad = '0';
	if (ops->prec != -1 && ft_ismatch(ops->spec, 5, INT, DEC, S_HEX, L_HEX,
			U_INT))
		pad = ' ';
	if (ops->spec == STR && (int)ft_strlen(input_str) > ops->prec
		&& ops->prec >= 0)
		input_str[ops->prec - is_shift] = '\0';
	if (ft_ismatch(ops->spec, 5, INT, DEC, U_INT, S_HEX, L_HEX)
		&& ops->prec == 0 && ft_ischain(input_str, '0'))
		ft_memset(input_str, '\0', 2);
	tmp = ft_strjoin(pref, input_str);
	if (tmp == NULL)
		return (NULL);
	out = pad_and_move_to_edge(tmp, len, pad, (!(ops->flgs[PAD_LEFT])));
	return (free(tmp), apply_offset(ops, out), out);
}
