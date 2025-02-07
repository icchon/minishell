#include "minishell.h"

char	*replace_env_vars(char *str, char **env)
{
	size_t	i;
	char	*key;
	char	*out;
	size_t	len;

	// int		in_double_quate;
	out = NULL;
	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			len = ft_calc_next_str(&str[++i], "\t\n\v\f\r \"$");
			key = ft_substr(&str[i], 0, len);
			if (ft_isequal(key, "?"))
				out = ft_strjoin_safe(out, ft_itoa(grobal_status(GET)), 1, 1);
			out = ft_strjoin_safe(out, ft_get_env(key, env), 1, 0);
			free(key);
		}
		else
		{
			if (str[i] == '\'' || str[i] == '\"')
			{
				i++;
			}
			len = ft_calc_next_str(&str[i], "$\"");
			out = ft_strjoin_safe(out, ft_substr(&str[i], 0, len), 1, 1);
		}
		i += len;
	}
	return (out);
}

static void	process_single_quate(char *str, size_t *i, char **out)
{
	size_t	len;
	char	*part;

	len = ft_calc_next_chr(&str[*i + 1], '\'');
	part = ft_substr(&str[*i], 0, len + 1);
	*out = ft_strjoin_safe(*out, part, 1, 1);
	(*i) += len + 2;
}

char	*replace_env_vars_quate(char *str, char **env)
{
	size_t	i;
	char	*out;
	char	*part;
	size_t	len;
	char	*tmp;

	i = 0;
	out = NULL;
	len = ft_calc_next_chr(&str[i], '\'');
	if (str[i] == '\'')
	{
		i++;
		process_single_quate(str, &(i), &out);
	}
	while (len > 0)
	{
		tmp = ft_substr(&str[i], 0, len);
		part = replace_env_vars(tmp, env);
		free(tmp);
		out = ft_strjoin_safe(out, part, 1, 1);
		i += len;
		if (str[i] == '\'')
		{
			i++;
			process_single_quate(str, &i, &out);
		}
		len = ft_calc_next_chr(&str[i], '\'');
	}
	return (out);
}

void	addback_tokens(t_token **token, t_token *new)
{
	t_token	*last_node;

	if (!new)
		return ;
	last_node = last_token(*token);
	new->prev = last_node;
	if (last_node == NULL)
	{
		*token = new;
		return ;
	}
	last_node->next = new;
	return ;
}

void	insert_token(t_token **dst, t_token *src)
{
	t_token	*last;
	t_token	*next;

	if (*dst)
	{
		*dst = src;
		return ;
	}
	next = (*dst)->next;
	(*dst)->next = src;
	if (src)
	{
		src->prev = (*dst);
	}
	last = last_token(src);
	if (last)
	{
		last->next = next;
	}
	if (next)
	{
		next->prev = last;
	}
	return ;
}

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

void	expander(t_astnode *node)
{
	t_token	*token;
	char	*tmp;
	size_t	cnt;
	t_token	*new_tokens;
	t_token	*to_add;

	cnt = 0;
	if (!node)
		return ;
	token = node->args;
	node->args = NULL;
	while (cnt < 2)
	{
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
		cnt++;
		if (cnt == 1)
		{
			token = node->redirects;
		}
	}
	expander(node->left);
	expander(node->right);
}
