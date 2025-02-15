NAME := minishell
CC := cc
INCDIR := ./src/includes/
C_FLAGS := -Wall -Wextra -Werror
LIBFT_DIR := ./libft/
LIBFT_ARCH := $(addsuffix libft.a, $(LIBFT_DIR))
INC_FLAGS :=  -I $(INCDIR) -I $(LIBFT_DIR)
BIN_DIR := ./bin
TARGET = ./bin/minishell

BUILTIN_FILES := builtin.c echo.c exit.c export_utils.c setenv.c cd.c env.c export.c pwd.c unset.c
BUILTIN_SRCS := $(addprefix builtin/,$(BUILTIN_FILES))

EXECUTER_FILES := execute_simple_command.c executer.c handle_io.c struct_pid_util.c execute_single_builtin.c executer_util.c process.c
EXECUTER_SRCS := $(addprefix executer/,$(EXECUTER_FILES))

PARSER_FILES := parse_funcs.c parser.c parser_util.c struct_ast_util.c
PARSER_SRCS := $(addprefix parser/,$(PARSER_FILES))

SIGNAL_FILES := signal.c
SIGNAL_SRCS := $(addprefix signal/,$(SIGNAL_FILES))

CORE_FILES := main_loop.c struct_all_util.c
CORE_SRCS := $(addprefix core/,$(CORE_FILES))

EXPANDER_FILES := expand_quate.c expand_vars.c expander.c
EXPANDER_SRCS := $(addprefix expander/,$(EXPANDER_FILES))

LEXER_FILES := lexer.c struct_token_util1.c struct_token_util3.c split.c struct_token_util2.c tokenizer.c
LEXER_SRCS := $(addprefix lexer/,$(LEXER_FILES))

READLINE_FILES := readline.c
READLINE_SRCS := $(addprefix readline/,$(READLINE_FILES))

SYNTAX_ANALYZER_FILES := analyze_funcs.c  brackets.c quate.c syntax_analyzer.c validate_input.c bracket_analyze_func.c
SYNTAX_ANALYZER_SRCS := $(addprefix syntax_analyzer/,$(SYNTAX_ANALYZER_FILES))

ENV_FILES := struct_env_util1.c struct_env_util2.c	struct_env_util3.c
ENV_SRCS := $(addprefix env/,$(ENV_FILES))

HEREDOC_FILES := heredoc.c heredoc_child.c heredoc_parent.c
HEREDOC_SRCS := $(addprefix heredoc/,$(HEREDOC_FILES))

SEMANTIC_ANALYZER_FILES := semantic_analyzer.c struct_exast_util.c
SEMANTIC_ANALYZER_SRCS := $(addprefix semantic_analyzer/,$(SEMANTIC_ANALYZER_FILES))

UTILS_FILES := grobal_vars1.c path.c split_set.c grobal_vars2.c split_quatesafe.c split_withsep.c
UTILS_SRCS := $(addprefix utils/,$(UTILS_FILES))

FILES := $(BUILTIN_SRCS) $(EXECUTER_SRCS) $(PARSER_SRCS) $(SIGNAL_SRCS) \
			$(CORE_SRCS) $(EXPANDER_SRCS) $(LEXER_SRCS) $(READLINE_SRCS) \
			$(SYNTAX_ANALYZER_SRCS) $(ENV_SRCS) $(HEREDOC_SRCS) $(SEMANTIC_ANALYZER_SRCS) \
			$(UTILS_SRCS) main.c

SRCS := $(addprefix ./src/,$(FILES))
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(BIN_DIR):
	@mkdir -p $@

$(TARGET): $(OBJS) $(LIBFT_ARCH) $(BIN_DIR)
	$(CC) $(C_FLAGS) -l readline $(INC_FLAGS) $(OBJS) $(LIBFT_ARCH) -o $@

$(LIBFT_ARCH):
	make -C $(LIBFT_DIR)

.c.o: 
	$(CC) $(C_FLAGS) $(INC_FLAGS) -c $< -o $@ 

clean: 
	rm -rf $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(BIN_DIR) $(LIBFT_ARCH)

bonus: all

re: fclean all

leak: all
	valgrind --leak-check=full --trace-children=no --track-fds=yes ./bin/minishell

.PHONY: all clean fclean re leak bonus 