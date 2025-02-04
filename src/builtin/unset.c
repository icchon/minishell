
#include "minishell.h"


t_env	*new_env_node(const char *env)
{
	t_env	*node;

	node = malloc(sizeof(t_env));
	if (!node)
		exit(EXIT_FAILURE);
	node->value = ft_strdup(env);
	if (!node->value)
	{
		free(node);
		exit(EXIT_FAILURE);
	}
	node->next = NULL;
	return (node);
}

t_env	*create_env_list(char **envp)
{
	t_env	*head;
	t_env	*tail;
	t_env	*node;

	head = NULL;
	tail = NULL;
	while (*envp)
	{
		node = new_env_node(*envp);
		if (!head)
		{
			head = node;
			tail = node;
		}
		else
		{
			tail->next = node;
			tail = node;
		}
		envp++;
	}
	return (head);
}

void	print_env_list(t_env *env_list)
{
	while (env_list)
	{
		printf("%s\n", env_list->value);
		env_list = env_list->next;
	}
}

void	free_env_list(t_env *env_list)
{
	t_env	*tmp;

	while (env_list)
	{
		tmp = env_list;
		env_list = env_list->next;
		free(tmp->value);
		free(tmp);
	}
}

static int	unset_env(t_env **env_list, const char *varname)
{
	size_t	name_len;
	t_env	*curr;
	t_env	*prev;

	name_len = strlen(varname);
	curr = *env_list;
	prev = NULL;
	while (curr)
	{
		if (strncmp(curr->value, varname, name_len) == 0
			&& curr->value[name_len] == '=')
		{
			if (prev == NULL)
				*env_list = curr->next;
			else
				prev->next = curr->next;
			free(curr->value);
			free(curr);
			return (0);
		}
		prev = curr;
		curr = curr->next;
	}
	return (0);
}

int	builtin_unset(int ac, char *av[], char **envp)
{
	t_env	*env_list;
	int		i;

	i = 1;
	env_list = create_env_list(envp);
	printf("Before unset:\n");
	print_env_list(env_list);
	while (i < ac)
	{
		if (!unset_env(&env_list, av[i]))
			printf("[DEBUG] Unset variable: %s\n", av[i]);
		i++;
	}
	printf("\nAfter unset:\n");
	print_env_list(env_list);
	free_env_list(env_list);
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