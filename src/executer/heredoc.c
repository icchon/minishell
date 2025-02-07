#include "minishell.h"

static char	*trim_quate(char *limiter)
{
	char	*out;

	out = ft_strtrim(limiter, "'\"");
	free(limiter);
	return (out);
}

static char	*process_heredoc(char *limiter)
{
	char	*input_file;
	char	buff[BUFFER_SIZE];
	char	tmp[BUFFER_SIZE];
	char	*enved;
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
		if (ft_isequal(limiter, tmp) || !*tmp)
			break ;
		ft_strlcat(buff, tmp, BUFFER_SIZE);
		ft_strlcat(buff, "\n", BUFFER_SIZE);
	}
	fd = open(input_file, O_WRONLY);
	enved = replace_env_vars_quate(buff, grobal_env(GET));
	ft_putstr_fd(enved, fd);
	return (free(enved), close(fd), input_file);
}

void	exec_heredoc(t_astnode *node)
{
	t_redirect	*redirect;
	char		*limiter;
	char		*input_file;

	if (!node)
	{
		return ;
	}
	redirect = node->redirects;			printf("limiter : [%s]\n", limiter);
	while (redirect)
	{
		if (redirect->type == TK_LIMITER)
		{
			limiter = redirect->data;
			limiter = trim_quate(limiter);
			input_file = process_heredoc(limiter);
			grobal_tmpfile(SET, input_file);
			redirect->data = ft_strdup(input_file);
			redirect->type = TK_INPUT_FILE;
			free(limiter);
		}
		redirect = redirect->next;
	}
	exec_heredoc(node->left);
	exec_heredoc(node->right);
}
