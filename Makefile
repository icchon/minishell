SCRIPT_LOCK := .script_lock

all:
	make -C ./src

clean: 
	make -C ./src clean

fclean: script_clean
	make -C ./src fclean

re: 
	make -C ./src re

$(SCRIPT_LOCK):
	./script/build_image.sh
	./script/run_container.sh
	touch $(SCRIPT_LOCK)

script_clean:
	rm -f $(SCRIPT_LOCK)

test: $(SCRIPT_LOCK)
	docker container exec minishell make -C test/googletest test

leak: all
	valgrind --leak-check=full  --suppressions=ignore_readline.supp ./bin/minishell

.PHONY: test clean re fclean all script_clean