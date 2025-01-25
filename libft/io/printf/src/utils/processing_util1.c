/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_util1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 10:27:00 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/22 14:38:46 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	move_flg_to_left(char *output_str)
{
	size_t	len;
	char	flg;
	size_t	i;

	len = ft_strlen(output_str);
	i = 0;
	while (i < len)
	{
		if (ft_ismatch(output_str[i], 3, ' ', '+', '-'))
		{
			flg = output_str[i];
			while (i >= 1)
			{
				output_str[i] = output_str[i - 1];
				i--;
			}
			output_str[0] = flg;
			return ;
		}
		i++;
	}
	return ;
}

void	move_hex_prefix_to_left(char *output_str, char *prefix)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(output_str);
	i = 0;
	while (i < len - 1)
	{
		if (ft_strncmp(&output_str[i], prefix, 2) == 0)
		{
			ft_memmove(output_str, prefix, 2);
			ft_memset(&output_str[ft_strlen(prefix)], '0', i);
			return ;
		}
		i++;
	}
	return ;
}

char	*get_prefix(t_options *ops, char *input_str)
{
	if (input_str[0] == '-' && ops->spec != NONE_SPEC && ops->spec != STR)
		return ("-");
	if (ops->flgs[SIGNED])
	{
		return ("+");
	}
	if (ops->flgs[SIGNED_SPACE])
	{
		return (" ");
	}
	if (ops->flgs[HEX_PREFIX])
	{
		if (ops->spec == S_HEX && !ft_ischain(input_str, '0'))
		{
			return ("0x");
		}
		if (ops->spec == L_HEX && !ft_ischain(input_str, '0'))
		{
			return ("0X");
		}
	}
	return ("");
}

char	*pad_and_move_to_edge(const char *src, int len, char pad,
		int is_right_edge)
{
	char	*out;
	size_t	i;

	out = (char *)ft_calloc(len + 1, sizeof(char));
	ft_memset(out, pad, len);
	i = 0;
	if (is_right_edge)
	{
		while (i < ft_strlen(src))
		{
			out[len - 1 - i] = src[ft_strlen(src) - 1 - i];
			i++;
		}
	}
	else
	{
		while (i < ft_strlen(src))
		{
			out[i] = src[i];
			i++;
		}
		ft_memset(&out[i], ' ', (len - i));
	}
	return (out);
}
