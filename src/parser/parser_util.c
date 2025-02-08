#include "minishell.h"

static void	handle_token(t_astnode *node, t_token **token)
{
	t_token	*to_delete;
	t_token	*to_add;

	if (!ft_ismatch((*token)->type, 2, TK_WORD, TK_VALIABLE))
	{
		to_delete = (*token);
		(*token) = (*token)->next;
		cut_token(token, to_delete);
		to_add = (*token);
		(*token) = (*token)->next;
		addback_token(&node->redirects, to_add);
		return ;
	}
	to_add = (*token);
	(*token) = (*token)->next;
	node->type = ASTND_CMD;
	addback_token(&node->args, to_add);
}

static void	create_node_prop(t_astnode *node, t_token **token)
{
	while (*token && ft_ismatch((*token)->type, 6, TK_WORD, TK_VALIABLE,
			TK_REDIRECT_IN, TK_HERE_DOC, TK_REDIRECT_OUT,
			TK_REDIRECT_OUT_APPEND))
	{
		handle_token(node, token);
	}
}

static t_astnode	*parse_cmd(t_token **token)
{
	t_astnode	*node;

	if (!*token)
		return (NULL);
	node = new_astnode();
	create_node_prop(node, token);
	return (node);
}

static t_astnode	*parse_pipe(t_token **token)
{
	t_astnode	*left;
	t_astnode	*root;
	t_astnode	*right;
	t_token		*to_delete;

	left = parse_cmd(token);
	if (!left)
		return (NULL);
	while (*token && ((*token)->type == TK_PIPE))
	{
		root = new_astnode();
		root->type = ASTND_PIPE;
		to_delete = (*token);
		(*token) = (*token)->next;
		cut_token(token, to_delete);
		right = parse_cmd(token);
		if (!right)
			return (NULL);
		root->left = left;
		root->right = right;
		left = root;
	}
	return (left);
}

t_astnode	*parse_or_and(t_token **token)
{
	t_astnode	*root;
	t_astnode	*left;
	t_token		*to_delete;

	left = parse_pipe(token);
	while (*token && ((*token)->type == TK_OR || (*token)->type == TK_AND))
	{
		root = new_astnode();
		if ((*token)->type == TK_OR)
			root->type = ASTND_OR;
		else
			root->type = ASTND_AND;
		to_delete = (*token);
		(*token) = (*token)->next;
		cut_token(token, to_delete);
		root->right = parse_pipe(token);
		if (!root->right)
			return (left);
		root->left = left;
		left = root;
	}
	return (left);
}
