
#include "builtin.h"

static int	unset_env(t_env **env_list, const char *varname)
{
	t_env	*curr;
	t_env	*prev;

	curr = *env_list;
	prev = NULL;
	while (curr)
	{
		if (ft_isequal(curr->key, (char *)varname))
		{
			if (prev == NULL)
				*env_list = curr->next;
			else
				prev->next = curr->next;
			free_env_node(curr);
			return (0);
		}
		prev = curr;
		curr = curr->next;
	}
	return (0);
}

int	builtin_unset(int ac, char *av[], t_env **env_list)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!unset_env(env_list, av[i]))
			i++;
	}
	return (EXIT_SUCCESS);
}

// int	main(int argc, char *argv[], char **envp)
// {
// 	builtin_unset(argc, argv, envp);
// }

// ↑複数できる、　$対応できてない, export消せる
// shell変数はexportすれば子プロセスに環境が引き継がれるからとれる
// shell変数、環境変数、
// exportコマンドで環境変数を設定することができるが、この場合でもunsetコマンドで削除できる。
//先頭が数字の変数名許可しない, から文字列もだめ　exportも
// unset $環境変数名 では環境変数は削除できません
// unset _　受け付ける
// unset 数字　本家だとエラーださない、どんな処理してる？
// unset HOME　で消せる
// 本家は env が実行ファイル（外部コマンド）として提供されるから、unset PATH で実行できなくなる。
//ミニシェルは env をビルトインで作っているので実行可能
//ビルトイン関数とは、シェル自体に組み込まれているコマンドなので、PATH を使わずに呼び出せる
// unset PATH をしても、ミニシェルの中で env コマンドはシェル内部の関数として処理されるため、問題なく動作