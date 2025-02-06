#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>

# define INPUT 0
# define OUTPUT 1
# define READ 0
# define WRITE 1
# define CHILD_PID 0
# define PARENT_PID 1
# define GET 0
# define SET 1
# define BUFFER_SIZE 1000
# define ASCII_SIZE 128

extern int				g_signal;

typedef enum e_token_type
{
	TK_WORD,
	TK_PIPE,
	TK_OR,
	TK_AND,
	TK_HERE_DOC,
	TK_LIMITER,
	TK_INPUT_FILE,
	TK_OUTPUT_FILE,
	TK_OUTPUT_FILE_APPEND,
	TK_REDIRECT_OUT = '>',
	TK_REDIRECT_OUT_APPEND,
	TK_REDIRECT_IN = '<',
	TK_UNDEFINED,
}						t_token_type;

typedef struct s_token
{
	t_token_type		type;
	char				*data;
	struct s_token		*prev;
	struct s_token		*next;
}						t_token;

typedef enum e_lexer_status
{
	IN_SINGLE_QAOT = '\'',
	IN_DOUBLE_QUOT = '\"',
	NORMAL = '\0',
}						t_lexer_status;

typedef enum e_astnode_type
{
	ASTND_PIPE,
	ASTND_OR,
	ASTND_AND,
	ASTND_CMD,
	ASTND_UNDEFINED,
}						t_astnode_type;

typedef enum e_ex_astnode_type
{
	EX_ASTND_OR,
	EX_ASTND_AND,
	EX_ASTND_PIPETOP,
}						t_ex_astnode_type;

typedef struct s_ex_astnode
{
	t_ex_astnode_type	type;
	t_list				*cmds;
	struct s_ex_astnode	*left;
	struct s_ex_astnode	*right;
}						t_ex_astnode;

typedef t_token			t_redirect;
typedef t_token			t_arg;
typedef t_token			t_cmd;
typedef void			*(*t_fvoid)(void *, ...);

typedef struct s_astnode
{
	t_astnode_type		type;
	t_cmd				*cmd;
	int					is_last_cmd;
	int					is_first_cmd;
	char				**arg_strs;
	t_arg				*args;
	t_redirect			*redirects;
	size_t				arg_cnt;
	struct s_astnode	*left;
	struct s_astnode	*right;
}						t_astnode;

typedef struct s_pids
{
	pid_t				pid;
	struct s_pids		*next;
}						t_pids;

typedef struct s_all
{
	char				*line;
	char				**env;
	t_token				*tokens;
	t_astnode			*tree;
	t_ex_astnode		*ex_tree;
}						t_all;

typedef unsigned char	t_status;

typedef struct s_env
{
	char				*value;
	struct s_env		*next;
}						t_env;

int						builtin_env(char **envp);
int						builtin_pwd(void);
int						builtin_unset(int ac, char *av[], char **envp);
int						builtin_echo(int ac, char *av[]);
int						builtin_exit(int argc, char *argv[], int last_status);

void					exec_heredoc(t_astnode *node);
pid_t					fork_and_exec_child(t_astnode *node, int old_pipes[2],
							int new_pipes[2]);
t_status				executer(t_ex_astnode *root);
void					expander(t_astnode *node);
char					**grobal_env(int get_or_set, ...);
t_token					*lexer(char *line);
t_token					*new_token(t_token_type type, char *data);
t_token					*last_token(t_token *token);
void					addback_token(t_token **token, t_token *newtoken);
void					addfront_token(t_token **token, t_token *newtoken);
t_token					*head_token(t_token *token);
size_t					size_token(t_token *token);
void					delone_token(t_token *token, void (*del)(void *));
void					cut_token(t_token **token, t_token *to_delete);
void					print_tokens(t_token *token);
void					print_token(t_token *token);
int						tokenizer(t_token **token_ptr);
t_astnode				*new_astnode(void);
void					add_astnode(t_astnode **root, t_astnode *left,
							t_astnode *right);
void					print_tree(t_astnode *root);
t_astnode				*parser(t_token *token);
int						is_directory(char *str);
int						is_command(char *str);
char					*replace_env_vars(char *str, char **env);
char					*replace_env_vars_quate(char *str, char **env);
void					free_astnode(t_astnode *root);
void					free_tokens(t_token *token);
void					free_asttree(t_astnode *root);
t_astnode				*parse_or_and(t_token **token);
char					*grobal_tmpfile(int get_or_set, ...);
void					check_fds(t_astnode *tree);
void					read_and_print(void);
t_pids					*new_pids(pid_t pid);
void					print_pids(t_pids *pids);
t_pids					*last_pid(t_pids *lst);
void					addback_pid(t_pids **lst, t_pids *newpid);
char					**create_args(t_astnode *node);
void					set_arginfo(t_astnode *node);
t_ex_astnode			*semantic_analyzer(t_astnode *root);
void					print_cmd(t_astnode *cmd_node, int depth);
void					print_ex_tree(t_ex_astnode *root);
t_ex_astnode			*new_ex_astnode(t_ex_astnode_type type);
pid_t					*create_pids(int n);
int						**create_pipes(int n);
void					free_ex_asttree(t_ex_astnode *node);
int						builtin_pwd(void);
char					*get_shell_prompt(int exist_nl);
char					*trim_space(char *line);
t_status				grobal_status(int get_or_set, ...);
t_status				builtin(char *av[]);
int						is_builtin(char *cmd);

#endif