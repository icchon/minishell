#include "sample.h"
#include <gtest/gtest.h>
#include <iostream>

extern "C"
{
#include "minishell.h"
#include <fcntl.h>
#include <stdlib.h>

};



TEST(ExpanderTest, TRUE){
	char *res;
	res = replace_env_vars("\"$HOME\"", __environ);
	dprintf(2, "res : %s\n", res);
	ASSERT_TRUE(ft_isequal(res, "/root"));
}