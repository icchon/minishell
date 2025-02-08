#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	builtin_env(char **envp)
{
	while (*envp)
	{
		ft_putendl_fd(*envp, STDOUT_FILENO);
		envp++;
	}
	return (EXIT_SUCCESS);
}

// int	main(int ac, char *av[], char **envp)
// {
// 	(void)ac;
// 	(void)av;
// 	if (setenv("_", "/usr/bin/env", 1) != 0)
// 	{
// 		perror("setenv");
// 		return (EXIT_FAILURE);
// 	}
// 	builtin_env(envp);
// }

// https://pubs.opengroup.org/onlinepubs/9699919799/utilities/env.html
// setenv必要か、
// 必要ない、最後の実行環境が./minishellとわかったほうがよさそう
// unset PATHのあと/usr/bin/envだとできる
//　外部コマンドだからPATHを参照しているのでPATHがないと実行できない
//  echo は使える、つまりPATHを参照していないビルトインコマンドとなる