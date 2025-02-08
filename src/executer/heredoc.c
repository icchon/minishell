#include "minishell.h"

static char	*loop(t_bufferio *stdin, char *delimited);
static char	*here_doc_read(t_bufferio *stdin, char *delimited, size_t *line);
static int	check_delimited(t_strgen *strgen, char *str, char *delimited,
				size_t delimited_len);
static void	put_error(size_t line, char *delimited);

char	*here_doc(char *delimited)
{
	char		*ret;
	t_bufferio	*stdin;

	stdin = ft_bufferionew(STDIN_FILENO, 0);
	if (!stdin)
	{
		perror("stdin");
		return (NULL);
	}
	ret = loop(stdin, delimited);
	if (!ret && stdin->strgen->error)
		perror("here_doc");
	ft_bufferiodel(stdin, 0);
	return (ret);
}

static char	*loop(t_bufferio *stdin, char *delimited)
{
	t_strgen	*strgen;
	size_t		delimited_len;
	size_t		line;
	char		*temp;

	delimited_len = ft_strlen(delimited);
	strgen = ft_strgeninit();
	if (!strgen)
		return (NULL);
	line = 0;
	while (1)
	{
		temp = here_doc_read(stdin, delimited, &line);
		if (!temp)
			break ;
		if (check_delimited(strgen, temp, delimited, delimited_len))
		{
			temp = ft_strgencomp(strgen);
			break ;
		}
	}
	ft_strgendel(strgen);
	return (temp);
}

static char	*here_doc_read(t_bufferio *stdin, char *delimited, size_t *line)
{
	char	*temp;

	ft_putstr_fd("> ", STDOUT_FILENO);
	temp = ft_readline(stdin);
	if (!temp)
		put_error(*line, delimited);
	(*line)++;
	return (temp);
}

static int	check_delimited(t_strgen *strgen, char *str, char *delimited,
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

static void	put_error(size_t line, char *delimited)
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

static char	*trim_quate(char *limiter)
{
	char	*out;

	out = ft_strtrim(limiter, "'\"");
	free(limiter);
	return (out);
}

static char	*process_heredoc(char *limiter)
{
	char	*res;
	char	*input_file;
	int		fd;

	res = here_doc(limiter);
	input_file = ft_create_random_file(".", ".tmp");
	fd = open(input_file, O_WRONLY | O_APPEND | O_CREAT,
			S_IRGRP | S_IROTH | S_IWUSR | S_IRUSR);
	ft_putstr_fd(res, fd);
	close(fd);
	return (input_file);
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
	redirect = node->redirects;
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
