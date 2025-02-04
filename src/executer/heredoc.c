#include "minishell.h"

static char	*process_heredoc(char *limiter)
{
	char	*input_file;
	char	buff[BUFFER_SIZE];
	char	tmp[BUFFER_SIZE];
	int		fd;

	ft_bzero(buff, BUFFER_SIZE);
	input_file = ft_create_random_file(".tmp");
	grobal_tmpfile(SET, input_file);
	while (1)
	{
		ft_putstr_fd("heredoc> ", STDOUT_FILENO);
		ft_bzero(tmp, BUFFER_SIZE);
		read(STDIN_FILENO, tmp, BUFFER_SIZE);
		tmp[ft_strlen(tmp) - 1] = '\0';
		if (ft_isequal(limiter, tmp))
			break ;
		ft_strlcat(buff, tmp, BUFFER_SIZE);
		ft_strlcat(buff, "\n", BUFFER_SIZE);
	}
	fd = open(input_file, O_WRONLY);
	ft_putstr_fd(buff, fd);
	close(fd);
	return (input_file);
}

void	exec_heredoc(t_astnode *node)
{
	t_redirect	*redirect;
	char		*limiter;

	if (!node)
	{
		return ;
	}
	redirect = node->redirects;
	while (redirect)
	{
		if (redirect->type == TK_LIMITER)
		{
			limiter = redirect->data;
			redirect->data = process_heredoc(limiter);
			redirect->data = replace_env_vars(redirect->data, grobal_env(GET,
						NULL));
			redirect->type = TK_INPUT_FILE;
			free(limiter);
		}
		redirect = redirect->next;
	}
	exec_heredoc(node->left);
	exec_heredoc(node->right);
}
