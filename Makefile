
all:
	make -C src

clean: 
	make -C src clean

fclean: 
	make -C src fclean

re: 
	make -C src re

test:
	./script/build_image.sh
	./script/run_container.sh
	docker container exec minishell make -C test/googletest test

.PHONY: test clean re fclean all 
