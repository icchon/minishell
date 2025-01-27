NAME := test.out
SRCS := sample_test.cpp sample.cpp
INCDIR := ./
FLAGS := -pthread -lgtest_main -lgtest
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	g++ $(FLAGS) -I $(INCDIR) $(OBJS) -o $@
	chmod +x $@

.cpp.o: 
	g++ $(FLAGS) -c $< -o $@

test: $(NAME) 
	./$(NAME)

clean: 
	rm -r $(OBJS) 

fclean: clean
	rm -r $(NAME)

re: fclean all

.PHONY: test clean re fclean all 