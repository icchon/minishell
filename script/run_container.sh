if ! docker container ls | grep minishell; then
	docker container run -d -u 0 -it -v  ${PWD}:/home/minishell/ --name minishell minishell/ubuntu:latest
fi