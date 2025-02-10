all:
	make -C ./src

clean: 
	make -C ./src clean

fclean: script_clean
	make -C ./src fclean

re: 
	make -C ./src re

leak: all
	valgrind --leak-check=full  --suppressions=ignore_readline.supp ./bin/minishell

.PHONY: clean re fclean all 