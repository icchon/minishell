
#include "builtin.h"

static int	get_exit_code(char *av)
{
	int	exit_code;
	int	tmp_exit_code;

	if (!ft_isint(av))
	{
		printf("exit: %s: numeric argument required\n", av);
		exit(2);
	}
	exit_code = ft_atoi(av);
	tmp_exit_code = exit_code;
	if (exit_code < 0)
		exit_code &= 0xFF;
	else
		while (tmp_exit_code > 256)
		{
			exit_code = tmp_exit_code % 256;
			tmp_exit_code /= 256;
		}
	return (exit_code);
}

int	builtin_exit(int ac, char *av[], int last_status)
{
	if (ac == 1)
	{
		printf("exit\n");
		exit(last_status);
	}
	else if (ac == 2)
	{
		printf("exit\n");
		exit(get_exit_code(av[1]));
	}
	else
	{
		ft_putendl_fd("exit: too many arguments", STDERR_FILENO);
		return (1);
	}
	return (0);
}

// int	main(int argc, char *argv[], char **envp)
// {
// 	(void)envp;
// 	return (builtin_exit(argc, argv, 0));
// }
//、直前の終了状態 last_status を仮に与えています

// exit 引数 複数、マイナス、long_max
// 終了ステータス#endif

/* NULL-terminated array of "NAME=VALUE" environment variables.  */
// extern char **__environ;
// 数字が範囲外、exitする(bash: exit: 222222222222222222222222222222: numeric argument required)
// exit() を 複数回呼び出した場合の動作は未定義
