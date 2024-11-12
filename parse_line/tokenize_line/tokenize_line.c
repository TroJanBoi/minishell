/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:45:22 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/07 18:43:00 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../token/token.h"

t_token	*get_token(char *line);

t_list	*tokenize_line(char *line)
{
	t_list	*tokens;
	t_token	*token;

	tokens = NULL;
	while (1)
	{
		while (*line == ' ' || *line == '\t')
			line++;
		if (*line == '\0')
			break ;
		token = get_token(line);
		if (token == NULL)
		{
			ft_lstclear(&tokens, free_token);
			return (NULL);
		}
		if (ft_lstnew_add_back(&tokens, token) == NULL)
		{
			free(token);
			ft_lstclear(&tokens, free_token);
			return (NULL);
		}
		line += ft_strlen(token->str);
	}
	return (tokens);
}
