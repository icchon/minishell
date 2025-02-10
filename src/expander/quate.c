/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quate.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:11:53 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/10 15:11:54 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_single_quate(char *str)
{
	int	single_left;
	int	double_left;
	int	single_right;
	int	double_right;

	if (ft_strlen(str) <= 1)
		return (0);
	single_left = ft_calc_next_chr(str, '\'');
	single_right = ft_calc_back_chr(str, '\'');
	double_left = ft_calc_next_chr(str, '\"');
	double_right = ft_calc_back_chr(str, '\"');
	if (single_left < single_right && single_left < double_left
		&& double_right < single_right)
		return (1);
	return (0);
}

int	is_double_quate(char *str)
{
	int	single_left;
	int	double_left;
	int	single_right;
	int	double_right;

	if (ft_strlen(str) <= 1)
		return (0);
	single_left = ft_calc_next_chr(str, '\'');
	single_right = ft_calc_back_chr(str, '\'');
	double_left = ft_calc_next_chr(str, '\"');
	double_right = ft_calc_back_chr(str, '\"');
	if (double_left < double_right && double_left < single_left
		&& single_right < double_right)
		return (1);
	return (0);
}

char	*trim_quate(char *str)
{
	char	*out;
	int		left;
	int		right;
	char	quate;

	if (ft_strlen(str) < 2)
		return (NULL);
	if (!(is_double_quate(str) || is_single_quate(str)))
		return (ft_strdup(str));
	quate = '\'';
	if (is_double_quate(str))
		quate = '"';
	left = ft_calc_next_chr(str, quate);
	right = ft_calc_back_chr(str, quate);
	out = ft_substr(str, 0, left);
	out = ft_strjoin_safe(out, ft_substr(str, left + 1, (right - left - 1)), 1,
			1);
	out = ft_strjoin_safe(out, ft_substr(str, right + 1, (ft_strlen(str) - right
					- 1)), 1, 1);
	return (out);
}
