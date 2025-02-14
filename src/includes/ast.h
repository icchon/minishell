/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:25:07 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/14 19:12:03 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

# include "libft.h"
# include "signals.h"
# include "token.h"

typedef enum e_astnode_type
{
	ASTND_PIPE,
	ASTND_OR,
	ASTND_AND,
	ASTND_CMD,
	ASTND_BRA,
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

typedef struct s_astnode
{
	t_astnode_type		type;
	int					is_last_cmd;
	int					is_first_cmd;
	char				**arg_strs;
	t_arg				*args;
	t_redirect			*redirects;
	size_t				arg_cnt;
	struct s_astnode	*left;
	struct s_astnode	*right;
}						t_astnode;

t_astnode				*new_astnode(void);
void					add_astnode(t_astnode **root, t_astnode *left,
							t_astnode *right);
void					print_tree(t_astnode *root);
t_astnode				*parser(t_token *token);
void					free_astnode(t_astnode *root);
void					free_asttree(t_astnode *root);
t_astnode				*parse_or_and(t_token **token);
t_ex_astnode			*semantic_analyzer(t_astnode *root);
void					print_cmd(t_astnode *cmd_node, int depth);
void					print_ex_tree(t_ex_astnode *root);
t_ex_astnode			*new_ex_astnode(t_ex_astnode_type type);
void					free_ex_asttree(t_ex_astnode *node);
t_astnode				*get_val(t_list *lst);
void					exec_heredoc(t_astnode *node);
void					handle_token(t_astnode *node, t_token **token);
void					create_node_prop(t_astnode *node, t_token **token);

#endif