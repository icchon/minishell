#include "minishell.h"

void	check_fds(t_astnode *tree)
{
	t_token	*redirect;
	int		fd;

	if (!tree)
		return ;
	redirect = tree->redirects;
	while (redirect)
	{
		if (redirect->type == TK_INPUT_FILE)
			fd = open(redirect->data, O_RDONLY);
		else if (redirect->type == TK_OUTPUT_FILE)
			fd = open(redirect->data, O_WRONLY | O_TRUNC | O_CREAT,
					S_IRGRP | S_IROTH | S_IWUSR | S_IRUSR);
		else if (redirect->type == TK_OUTPUT_FILE_APPEND)
			fd = open(redirect->data, O_WRONLY | O_APPEND | O_CREAT,
					S_IRGRP | S_IROTH | S_IWUSR | S_IRUSR);
		if (fd == -1)
		{
			perror(redirect->data);
			return ;
		}
		redirect = (close(fd), redirect->next);
	}
	check_fds(tree->left);
	check_fds(tree->right);
}
