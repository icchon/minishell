#include "minishell.h"

void	put_error(size_t line, char *delimited)
{
	if (line)
	{
		ft_putstr_fd("line ", STDERR_FILENO);
		ft_putnbr_fd(line, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	ft_putstr_fd("warning: ", STDERR_FILENO);
	ft_putstr_fd("here-document at line 0 delimited by end-of-file ",
		STDERR_FILENO);
	ft_putstr_fd("(wanted `", STDERR_FILENO);
	ft_putstr_fd(delimited, STDERR_FILENO);
	ft_putstr_fd("')\n", STDERR_FILENO);
}

int	check_delimited(t_strgen *strgen, char *str, char *delimited,
		size_t delimited_len)
{
	if (!ft_strncmp(str, delimited, delimited_len)
		&& str[delimited_len] == '\n')
	{
		free(str);
		return (1);
	}
	else
	{
		ft_strgenstr(strgen, str);
		free(str);
		return (0);
	}
}
