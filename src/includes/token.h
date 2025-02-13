/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:25:29 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/13 15:15:25 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include "libft.h"
# include "type.h"
# include "util.h"

typedef enum e_token_type
{
	TK_WORD = 0,
	TK_VAR = 1,
	TK_PIPE = '|',
	TK_OR = '|' + ASCII_SIZE,
	TK_AND = '&' + ASCII_SIZE,
	TK_HEREDOC = '<' + ASCII_SIZE,
	TK_LIMITER = 2,
	TK_INFILE = 3,
	TK_OUTFILE = 4,
	TK_OUTFILE_APP = 5,
	TK_REDOUT = '>',
	TK_REDOUT_APP = '>' + ASCII_SIZE,
	TK_REDIN = '<',
	TK_BRA_LEFT = '(',
	TK_BRA_RIGHT = ')',
	TK_UNDEFINED = 6,
}					t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*data;
	struct s_token	*prev;
	struct s_token	*next;
}					t_token;

typedef t_token		t_redirect;
typedef t_token		t_arg;
typedef t_token		t_cmd;

t_token				*lexer(char *line);
t_token				*new_token(t_token_type type, char *data);
t_token				*last_token(t_token *token);
void				addback_token(t_token **token, t_token *newtoken);
void				addfront_token(t_token **token, t_token *newtoken);
t_token				*head_token(t_token *token);
size_t				size_token(t_token *token);
void				free_token(t_token *token);
void				cut_token(t_token **token, t_token *to_delete);
void				print_tokens(t_token *token);
void				print_token(t_token *token);
void				tokenizer(t_token *token_ptr);
void				free_tokens(t_token *token);
void				addback_tokens(t_token **token, t_token *new);
void				insert_token(t_token **dst, t_token *src);
char				**split_for_lexer(const char *str, const char *set);

#endif