/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:25:29 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/11 07:43:50 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include "libft.h"
# include "type.h"

typedef enum e_token_type
{
	TK_WORD,
	TK_VALIABLE,
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
}					t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*data;
	struct s_token	*prev;
	struct s_token	*next;
}					t_token;

typedef enum e_lexer_status
{
	IN_SINGLE_QAOT = '\'',
	IN_DOUBLE_QUOT = '\"',
	NORMAL = '\0',
}					t_lexer_status;

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
void				tokenizer(t_token **token_ptr);
void				free_tokens(t_token *token);
void				addback_tokens(t_token **token, t_token *new);
void				insert_token(t_token **dst, t_token *src);

#endif