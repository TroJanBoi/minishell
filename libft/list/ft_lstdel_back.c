/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:40:08 by nteechar          #+#    #+#             */
/*   Updated: 2024/10/25 11:21:53 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_list.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *));

// delete the first node in linked list
// if there's only one element in list, set *lst = NULL
void	ft_lstdel_back(t_list **lst, void (*del)(void *))
{
	t_list	*prev;
	t_list	*cur;

	if (lst == NULL)
		return ;
	prev = NULL;
	cur = *lst;
	while (cur->next != NULL)
	{
		prev = cur;
		cur = cur->next;
	}
	ft_lstdelone(cur, del);
	if (prev)
		prev->next = NULL;
	else
		*lst = NULL;
}
