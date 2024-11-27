/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combine_redirs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:52:56 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/15 15:10:33 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "parse_line.h"

void	combine_redirs(t_list **tokens)
{
	t_list	*node;
	t_token	*token;
	t_token	*next_token;

	node = *tokens;
	while (node)
	{
		token = node->content;
		if (is_redir(token->type))
		{
			next_token = node->next->content;
			free(token->str);
			token->str = next_token->str;
			free(next_token);
			ft_lstdelone(node->next, NULL);
		}
		node = node->next;
	}
}
