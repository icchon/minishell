
#include "minishell.h"

int	builtin_exit(int argc, char *argv[], int last_status)
{
	int	exit_code;
	int	flg_int;
	int	tmp_exit_code;

	if (argc == 1)
	{
		printf("exit\n");
		exit(last_status);
	}
	else if (argc == 2)
	{
		flg_int = ft_isint(argv[1]);
		if (!flg_int)
		{
			printf("exit: ");
			printf("%s", argv[1]);
			printf(": numeric argument required\n");
			// ft_putendl_fd(": numeric argument required", STDERR_FILENO);
			exit(2);
		}
		exit_code = ft_atoi(argv[1]);
		tmp_exit_code = exit_code;
		if (exit_code < 0)
			exit_code = exit_code & 0xFF;
		else
			while (tmp_exit_code > 256)
			{
				exit_code = tmp_exit_code % 256;
				tmp_exit_code /= 256;
			}
		printf("exit\n");
		exit((int)exit_code);
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
