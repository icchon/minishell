#include "minishell.h"

static int	echo_option(char *av)
{
	int	i;

	i = 1;
	if (!av || av[0] != '-')
		return (0);
	while (av[i])
	{
		if (av[i] != 'n')
			return (0);
		i++;
	}
	return (i > 1);
}

int	builtin_echo(int ac, char *av[])
{
	int	i;
	int	n_flg;

	i = 1;
	n_flg = 1;
	while (i < ac && echo_option(av[i]))
	{
		n_flg = 0;
		i++;
	}
	while (i < ac)
	{
		printf("%s", av[i]);
		if (i < ac - 1)
			printf(" ");
		i++;
	}
	if (n_flg)
		printf("\n");
    return(EXIT_SUCCESS);
}

// int	main(int argc, char *argv[])
// {
// 	builtin_echo(argc, argv);
// }

// echo -n option
// できてない
// echo -nnnnnnnのとき-nと同じ扱い、-nnnnannのとき引数として出力
// echo -n -n -n aaaのときaaaのみ出力
//できてる
// echo "$$"で9417が出力
// ./a.out $?でexit status出力される