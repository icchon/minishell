#include "minishell.h"

t_status	waitpids(t_list *cmds, pid_t *pids)
{
	int	i;
	int	status;

	i = 0;
	while (i < ft_lstsize(cmds))
	{
		waitpid(pids[i++], &status, 0);
		status = WEXITSTATUS(status);
	}
	return ((t_status)status);
}
