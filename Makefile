SCRIPT_LOCK := .script_lock

all:
	make -C src

clean: 
	make -C src clean

fclean: script_clean
	make -C src fclean

re: 
	make -C src re

$(SCRIPT_LOCK):
	./script/build_image.sh
	./script/run_container.sh
	touch $(SCRIPT_LOCK)

# Clean the script lock file
script_clean:
	rm -f $(SCRIPT_LOCK)

test: $(SCRIPT_LOCK)
	docker container exec minishell make -C test/googletest test

.PHONY: test clean re fclean all script_clean