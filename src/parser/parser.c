#include "minishell.h"

t_astnode	*parser(t_token *token)
{
	t_astnode	*ast_tree;

	ast_tree = parse_or_and(&token);
	exec_heredoc(ast_tree);
	return (ast_tree);
}
