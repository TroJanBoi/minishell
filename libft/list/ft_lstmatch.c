/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmatch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:37:16 by nteechar          #+#    #+#             */
/*   Updated: 2024/10/25 10:54:12 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "t_list.h"

// use "match" func and return the matched node, NULL if did not find
t_list	*ft_lstmatch(t_list *lst, int (*match)(void *))
{
	while (lst)
	{
		if (match(lst->content))
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
