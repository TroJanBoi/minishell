/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_add_back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:34:21 by nteechar          #+#    #+#             */
/*   Updated: 2024/09/18 14:29:08 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_list.h"
#include <unistd.h>

t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);

// return address of created node enveloping the content
// return NULL if cannot malloc new node
t_list	*ft_lstnew_add_back(t_list **lst, void *content)
{
	t_list	*node;

	node = ft_lstnew(content);
	if (node == NULL)
		return (NULL);
	ft_lstadd_back(lst, node);
	return (node);
}
