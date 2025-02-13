/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:22:56 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/13 15:22:57 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax.h"

int	is_valid_input(char *line)
{
	return (is_quate_closed(line) && is_valid_brackets(line));
}
