#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	builtin_env(t_env *envp)
{
	while (envp)
	{
		ft_putendl_fd(envp->value, STDOUT_FILENO);
		envp = envp->next;
	}
	return (EXIT_SUCCESS);
}
//=がない場合は出力させないという処理追加するかも

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