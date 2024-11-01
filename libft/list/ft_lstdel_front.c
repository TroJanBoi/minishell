/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:40:10 by nteechar          #+#    #+#             */
/*   Updated: 2024/10/25 11:21:55 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_list.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *));

// delete the first node in linked list
// if there's only one element in list, set *lst = NULL
void	ft_lstdel_front(t_list **lst, void (*del)(void *))
{
	t_list	*next_node;

	if (lst == NULL)
		return ;
	next_node = (*lst)->next;
	ft_lstdelone(*lst, del);
	*lst = next_node;
}
