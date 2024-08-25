/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:11:19 by nteechar          #+#    #+#             */
/*   Updated: 2024/05/29 15:34:38 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl_list	*gnl_ft_lstnew(void)
{
	t_gnl_list	*node;

	node = malloc(sizeof(t_gnl_list *));
	if (node == NULL)
		return (NULL);
	node->str = malloc(BUFFER_SIZE + 1);
	if (node->str == NULL)
	{
		free(node);
		return (NULL);
	}
	node->i = 0;
	node->next = NULL;
	return (node);
}

void	gnl_ft_lstdelone(t_gnl_list *lst)
{
	if (lst == NULL)
		return ;
	free(lst->str);
	free(lst);
}

void	gnl_ft_lstdel_front(t_gnl_list **lst)
{
	t_gnl_list	*temp_node;

	if (lst == NULL || *lst == NULL)
		return ;
	temp_node = *lst;
	*lst = (*lst)->next;
	gnl_ft_lstdelone(temp_node);
}

void	gnl_ft_lstclear(t_gnl_list **lst)
{
	if (lst == NULL || *lst == NULL)
		return ;
	while (*lst != NULL)
		gnl_ft_lstdel_front(lst);
}

void	gnl_ft_lstadd_back(t_gnl_list **lst, t_gnl_list *new)
{
	t_gnl_list	*node;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		node = *lst;
		while (node->next != NULL)
			node = node->next;
		node->next = new;
	}
}
