/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_env_util3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:58:27 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/11 08:25:07 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

char	*extract_key(const char *line)
{
	int	len;

	len = ft_calc_next_chr((char *)line, '=');
	return (ft_substr(line, 0, len));
}

char	*extract_value(const char *line)
{
	int	len;

	len = ft_calc_next_chr((char *)line, '=');
	return (ft_substr(line, len + 1, ft_strlen(line) - len - 1));
}

char	*concat_key_value(const char *key, const char *value)
{
	char	*out;

	out = ft_strjoin(key, "=");
	out = ft_strjoin_safe((char *)out, (char *)value, 1, 0);
	return (out);
}

char	*extract_key_plus(const char *line)
{
	int	len;

	len = ft_calc_next_chr((char *)line, '+');
	return (ft_substr(line, 0, len));
}
