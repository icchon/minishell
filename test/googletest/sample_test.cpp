#include "sample.h"
#include <gtest/gtest.h>
#include <iostream>

extern "C"
{
#include "minishell.h"
#include <fcntl.h>
#include <stdlib.h>

};

TEST(ExpanderTest, TRUE)
{
	char	**argv;
	int		argc;

	argv = __environ;
	argc = ft_strslen((const char **)argv);
	builtin_echo((int)argc, argv, 0);
}

