#include "minishell.h"

void	waitpids(t_list *cmds, pid_t *pids)
{
	int			i;
	t_status	status;

	i = 0;
	while (i < ft_lstsize(cmds))
	{
		waitpid(pids[i++], (int *)&(status), 0);
		grobal_status(SET, status);
	}
}
