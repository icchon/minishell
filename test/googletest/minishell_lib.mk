NAME     = libmsh.a
PROJECT_DIR = ../..
SRC_DIR  = $(PROJECT_DIR)/src
LIBFT_DIR = $(PROJECT_DIR)/libft
SRC      = $(shell find $(SRC_DIR) $(LIBFT_DIR) -name "*.c" -not -name "main.c")
CC       = cc
CFLAGS   = -Wall -Wextra -MMD -MP -g -O0 -I $(SRC_DIR)/includes -I $(PROJECT_DIR)/libft

CACHEDIR = cache
OBJS     = $(subst ./,,$(subst ../,,$(SRC:%=$(CACHEDIR)/%.o)))

all: $(NAME)

clean:
	@make -C $(SRC_DIR) clean

fclean: clean
	@make -C $(SRC_DIR) fclean
	@rm -rf $(NAME)

re: fclean all

$(NAME): $(OBJS) 
	@ar rcs $@ $(filter %.o,$^)

$(CACHEDIR)/%.c.o: $(PROJECT_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -o $@ -c $<

libft.a: 
	@make -C ../../libft 
