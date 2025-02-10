#include "minishell.h"
#include <error.h>
#include <stdio.h>

static int	valid_pwd(char *pwd)
{
	char	**component;
	char	*tmp_pwd;
	int		i;

	i = 0;
	if (!pwd || !(pwd && pwd[0] == '/') || ft_strlen(pwd) >= PATH_MAX)
		return (0);
	if (!(tmp_pwd = ft_strdup(pwd)))
		return (0);
	if (!(component = ft_split(tmp_pwd, '/')))
	{
		free(tmp_pwd);
		ft_2darraydel(component);
		return (0);
	}
	while (component[i])
	{
		if (ft_isequal(component[i], ".") || ft_isequal(component[i], ".."))
		{
			free(tmp_pwd);
			ft_2darraydel(component);
			return (0);
		}
		i++;
	}
	free(tmp_pwd);
  ft_2darraydel(component);
	return (1);
}

int	builtin_pwd(char **envp)
{
	char	*cwd_env;

	cwd_env = ft_get_env("PWD", envp);
	if (valid_pwd(cwd_env))
	{
		ft_putendl_fd(cwd_env, STDOUT_FILENO);
	}
	else
	{
		ft_putendl_fd(cwd_env, STDOUT_FILENO);
	}
	return (EXIT_SUCCESS);
}
// optionなしだと-Lに合わせるっぽい, manとposixで違う
// https://pubs.opengroup.org/onlinepubs/9699919799/utilities/pwd.html
// -Lだとシンボリック関係なくPWD環境変数に基づいて絶対パス表示
// シンボリックリンクはlstatで取れそうだけどどういうときに-Pになるかわからないし
// 沼だからやらない
// getcwd 引数ない(NULL)のときmallocで領域確保
