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
	expanded = expand_word((*token)->data);
	splited = ft_split(expanded, ' ');
	free(expanded);
	i = 0;
	new_tokens = NULL;
	while (splited && splited[i])
	{
		new = new_token(TK_WORD, ft_strdup(splited[i]));
		addback_token(&new_tokens, new);
		i++;
	}
	ft_2darraydel(splited);
	return (new_tokens);
}

void	expand_args(t_astnode *node)
{
	t_token	*token;
	char	*tmp;
	t_token	*new_tokens;
	t_token	*to_add;
	t_token	*to_delete;

	token = node->args;
	node->args = NULL;
	while (token)
	{
		if (token->type == TK_VALIABLE)
		{
			new_tokens = token_variable_split(&token);
			to_delete = token;
			token = token->next;
			cut_token(&to_delete, to_delete);
			addback_tokens(&node->args, new_tokens);
		}
		else
		{
			tmp = token->data;
			token->data = expand_word(tmp);
			to_add = token;
			token = token->next;
			addback_token(&node->args, to_add);
			free(tmp);
		}
	}
}

void	expand_redirects(t_astnode *node)
{
	t_token	*token;
	char	*tmp;
	t_token	*to_add;

	token = node->redirects;
	node->redirects = NULL;
	while (token)
	{
		tmp = token->data;
		token->data = expand_word(tmp);
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
	expand_redirects(node);
	expander(node->left);
	expander(node->right);
}
