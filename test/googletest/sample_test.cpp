#include "sample.h"
#include <gtest/gtest.h>
#include <iostream>

extern "C"
{
#include "minishell.h"
#include <fcntl.h>
#include <stdlib.h>

};

TEST(IsEvenTest, Negative)
{
	EXPECT_FALSE(IsEven(-1));
	EXPECT_TRUE(IsEven(-2));
}

TEST(IsEvenTest, Zero)
{
	EXPECT_TRUE(IsEven(0));
}

TEST(IsEvenTest, Positive)
{
	EXPECT_FALSE(IsEven(1));
	EXPECT_TRUE(IsEven(2));
}

TEST(IsCommandTest, True)
{
	EXPECT_TRUE(is_command("cmd"));
	EXPECT_FALSE(is_command("/cmd"));
}

TEST(StrlenTest, True)
{
	EXPECT_TRUE(ft_strlen("aiueo") == 5);
}