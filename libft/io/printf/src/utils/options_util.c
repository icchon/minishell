/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:43:30 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/22 16:26:53 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_options	*create_new_options(void)
{
	t_options	*ops;
	int			i;

	ops = (t_options *)malloc(sizeof(t_options) * 1);
	if (ops == NULL)
		return (NULL);
	i = 0;
	while (i < ASCII_SIZE)
	{
		ops->flgs[i] = 0;
		i++;
	}
	ops->spec = NONE_SPEC;
	ops->flgs[NONE_FLG] = 1;
	ops->prec = -1;
	ops->width = 0;
	return (ops);
}

void	update_options(t_options *ops)
{
	if (ft_ismatch(ops->spec, 3, DEC, INT, U_INT))
	{
		if (ops->flgs[PAD_LEFT])
		{
			ops->flgs[PAD_ZERO] = 0;
		}
	}
	if (ops->spec == STR)
	{
		ops->flgs[SIGNED_SPACE] = 0;
	}
	return ;
}

// void	print_options_for_debug(t_options *ops)
// {
// 	printf("-----------------------------------------\n");
// 	if (ops->flgs[PAD_LEFT])
// 		printf("flg : PAD_LEFT\n");
// 	else if (ops->flgs[PAD_ZERO])
// 		printf("flg : PAD_ZERO\n");
// 	else if (ops->flgs[SIGNED])
// 		printf("flg : SIGNED\n");
// 	else if (ops->flgs[SIGNED_SPACE])
// 		printf("flg : SIGNED_SPACE\n");
// 	else if (ops->flgs[NONE_FLG])
// 		printf("flg : NONE\n");
// 	else if (ops->flgs[HEX_PREFIX])
// 		printf("flg : HEX_PREFIX\n");
// 	else
// 		printf("Un Handled Error\n");
// 	printf("width : %d\n", ops->width);
// 	printf("precsion : %d\n", ops->prec);
// 	printf("specifer : %d\n", ops->spec);
// 	printf("-----------------------------------------\n");
// 	return ;
// }

t_options	*parse_command(char *command, va_list ap)
{
	t_options	*ops;
	char		*width_str;
	char		*prec_str;

	ops = create_new_options();
	if (ops == NULL)
		return (NULL);
	while (ft_contain(FLG_SET, *command))
		(ft_memset(&ops->flgs[NONE_FLG], 0, 1),
			ft_memset(&ops->flgs[(unsigned int)*(command++)], 1, 1));
	width_str = ft_substr(command, 0, ft_calc_next_chr(command, '.'));
	if (width_str == NULL)
		return (NULL);
	ops->width = ft_atoi(width_str);
	command += ft_strlen(width_str);
	if (ft_strncmp(width_str, "*", 1) == 0 && ft_strlen(width_str) == 1)
		ops->width = va_arg(ap, int);
	free(width_str);
	if (!ft_contain(command, '.'))
		return (ft_memset(&ops->prec, -1, 1), ops);
	prec_str = ft_strchr(command, '.') + 1;
	ops->prec = ft_atoi(prec_str);
	return (ops);
}

t_options	*create_options_obj(char *start_of_block, va_list ap)
{
	int			command_len;
	char		*command;
	t_options	*ops;
	t_specifer	spec;

	command_len = ft_calc_next_str(start_of_block, SPECIFER_SET);
	command = ft_substr(start_of_block, 0, command_len);
	if (command == NULL)
		return (NULL);
	ops = parse_command(command, ap);
	if (ops == NULL)
		return (NULL);
	free(command);
	spec = (t_specifer)start_of_block[command_len];
	ops->spec = spec;
	update_options(ops);
	return (ops);
}
