/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:55:04 by kaisobe           #+#    #+#             */
/*   Updated: 2024/12/24 00:34:55 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LST_H
# define FT_LST_H

# include "ft_algo.h"
# include <limits.h>
# include <stddef.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_twlist
{
	void			*content;
	struct s_twlist	*next;
	struct s_twlist	*prev;
}					t_twlist;

void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);

void				ft_twlstadd_back(t_twlist **lst, t_twlist *new);
void				ft_twlstadd_front(t_twlist **lst, t_twlist *new);
void				ft_twlstclear(t_twlist **lst, void (*del)(void *));
void				ft_twlstdelone(t_twlist *lst, void (*del)(void *));
t_twlist			*ft_twlstlast(t_twlist *lst);
t_twlist			*ft_twlsthead(t_twlist *lst);
t_twlist			*ft_twlstnew(void *content);
int					ft_twlstsize(t_twlist *lst);
int					ft_issortedtwlst(t_twlist *lst, int reversed);
t_twlist			*ft_twlstget(t_twlist *lst, int index);

#endif