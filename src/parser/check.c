#include "minishell.h"

t_status	check_fds(t_redirect *redirect)
{
	int			res;
	t_status	status;

	status = EXIT_SUCCESS;
	while (redirect)
	{
		res = access(redirect->data, F_OK);
		if (res == -1)
		{
			dprintf(2, "bash: %s: No such file or directory\n", redirect->data);
			status = 127;
		}
		else
		{
			if (redirect->type == TK_INPUT_FILE)
				res = access(redirect->data, R_OK);
			else if (redirect->type == TK_OUTPUT_FILE)
				res = access(redirect->data, W_OK);
			else if (redirect->type == TK_OUTPUT_FILE_APPEND)
				res = access(redirect->data, W_OK);
			if (res == -1)
			{
				dprintf(2, "bash: %s: Permission denied\n", redirect->data);
				status = 126;
			}
		}
		redirect = redirect->next;
	}
	return (status);
}
