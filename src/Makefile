NAME := minishell
CC := cc
INCDIR := ./includes/
C_FLAGS := -Wall -Wextra -Werror
LIBFT_DIR := ../libft/
LIBFT_ARCH := $(addsuffix libft.a, $(LIBFT_DIR))
INC_FLAGS :=  -I $(INCDIR) -I $(LIBFT_DIR)
BIN_DIR := ../bin
TARGET = ../bin/minishell

SRCS := $(shell find . -name "*.c" -o -name "*.c")
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(BIN_DIR):
	@mkdir -p $@

$(TARGET): $(OBJS) $(LIBFT_ARCH) $(BIN_DIR)
	$(CC) $(C_FLAGS) -l readline $(INC_FLAGS) $(OBJS) $(LIBFT_ARCH) -o $@

$(LIBFT_ARCH):
	@make -C $(LIBFT_DIR)

.c.o: 
	$(CC) $(C_FLAGS) $(INC_FLAGS) -c $< -o $@ 

clean: 
	rm -rf $(OBJS)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(BIN_DIR) $(LIBFT_ARCH)

bonus: all

re: fclean all

.PHONY: all clean fclean re 