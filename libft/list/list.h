/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:19:21 by nteechar          #+#    #+#             */
/*   Updated: 2024/10/25 11:21:45 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include "t_list.h"

void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdel_back(t_list **lst, void (*del)(void *));
void	ft_lstdel_front(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int		*ft_lstmatch_del(t_list **lst, int (*match)(void *),
			void (*del)(void *));
t_list	*ft_lstmatch(t_list *lst, int (*match)(void *));
t_list	*ft_lstnew_add_back(t_list **lst, void *content);
t_list	*ft_lstnew_add_front(t_list **lst, void *content);
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);

#endif
