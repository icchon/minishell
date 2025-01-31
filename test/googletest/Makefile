NAME := test.out
SRC_DIR = ../../src
SRC = $(shell find . -name "*.cpp" -o -name "*.c")
INCDIR := ./
FLAGS := -pthread -lgtest_main -lgtest
MK_MSH  = make -f minishell_lib.mk
CACHEDIR = cache
OBJS    = $(SRC:%=$(CACHEDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS) libmsh.a
	g++ $(FLAGS) -I $(INCDIR) -I $(SRC_DIR)/includes/ -I ../../libft/ $(OBJS) libmsh.a -o $@
	mkdir -p ../../bin
	

libmsh.a: $(shell find $(SRC_DIR) -name "*.c" -not -name "main.c")
	$(MK_MSH)

$(CACHEDIR)/%.c.o: %.c
	mkdir -p $(@D)
	cc $(FLAGS) -I $(INCDIR) -I $(SRC_DIR)/includes/ -I ../../libft/ -o $@ -c $<

$(CACHEDIR)/%.cpp.o: %.cpp
	mkdir -p $(@D)
	g++ $(FLAGS) -I $(INCDIR) -I $(SRC_DIR)/includes/ -I ../../libft/ -o $@ -c $<

test: $(NAME) 
	mv $(NAME) ../../bin
	../../bin/$(NAME)

clean: 
	$(MK_MSH) clean
	rm -rf $(CACHEDIR) 

fclean: clean
	$(MK_MSH) fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: test clean re fclean all 