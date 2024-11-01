/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmatch_del.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:53:41 by nteechar          #+#    #+#             */
/*   Updated: 2024/10/25 11:02:25 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "t_list.h"

void	ft_lstdel_front(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));

// use "match" func and delete the matched node
// return TRUE if found, FALSE if not found
int	ft_lstmatch_del(t_list **lst, int (*match)(void *), void (*del)(void *))
{
	t_list	*prev;
	t_list	*cur;

	if (lst == NULL)
		return ;
	if (match((*lst)->content))
	{
		ft_lstdel_front(lst, del);
		return (1);
	}
	prev = NULL;
	cur = *lst;
	while (cur != NULL)
	{
		if (match(cur->content))
		{
			prev = cur->next;
			ft_lstdelone(cur, del);
			return (1);
		}
		prev = cur;
		cur = cur->next;
	}
	return (0);
}
