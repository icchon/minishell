#include "minishell.h"

t_token	*token_variable_split(t_token **token)
{
	char	*expanded;
	char	**splited;
	t_token	*new_tokens;
	t_token	*new;
	size_t	i;

	if (!(*token && (*token)->type == TK_VALIABLE))
		return (NULL);
	expanded = replace_env_vars_quate((*token)->data, grobal_env(GET));
	splited = ft_split(expanded, ' ');
	free(expanded);
	if (!splited)
		return (NULL);
	i = 0;
	new_tokens = NULL;
	while (splited[i])
	{
		new = new_token(TK_WORD, splited[i]);
		addback_token(&new_tokens, new);
		i++;
	}
	return (new_tokens);
}

void	expand_args(t_astnode *node)
{
	t_token	*token;
	char	*tmp;
	t_token	*new_tokens;
	t_token	*to_add;

	token = node->args;
	node->args = NULL;
	while (token)
	{
		if (token->type == TK_VALIABLE)
		{
			new_tokens = token_variable_split(&token);
			addback_tokens(&node->args, new_tokens);
			token = token->next;
		}
		else
		{
			tmp = token->data;
			token->data = replace_env_vars_quate(tmp, grobal_env(GET));
			to_add = token;
			token = token->next;
			addback_token(&node->args, to_add);
			free(tmp);
		}
	}
}

void	expande_redirects(t_astnode *node)
{
	t_token	*token;
	char	*tmp;
	t_token	*to_add;

	token = node->redirects;
	node->redirects = NULL;
	while (token)
	{
		tmp = token->data;
		token->data = replace_env_vars_quate(tmp, grobal_env(GET));
		to_add = token;
		token = token->next;
		addback_token(&node->redirects, to_add);
		free(tmp);
	}
}

void	expander(t_astnode *node)
{
	if (!node)
		return ;
	expand_args(node);
	expande_redirects(node);
	expander(node->left);
	expander(node->right);
}
