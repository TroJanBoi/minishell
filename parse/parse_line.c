/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 18:07:12 by nteechar          #+#    #+#             */
/*   Updated: 2024/08/28 15:32:27 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

// a function to parse input line, return (pipeline)
// tokens: linked list, each node can be words, redirections or pipe
// pipeline: linked list, each node is a simple command
t_list	*parse_line(char *line)
{
	t_list	*tokens;
	t_list	*pipeline;  

	tokens = tokenize(line);
	if (tokens == NULL)
	{
		return (NULL);
	}
	expand(tokens);
	pipeline = parse_tokens(tokens);
	if (pipeline == NULL)
	{
		return (NULL);
	}
	return (pipeline);
}
