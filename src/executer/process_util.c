#include "minishell.h"

int	contain_backslash(char *str)
{
	if (ft_strchr(str, '/'))
		return (1);
	return (0);
}

