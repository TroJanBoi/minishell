/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:26:18 by nteechar          #+#    #+#             */
/*   Updated: 2024/10/16 17:02:10 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_line.h"
#include <stdio.h>
#include <errno.h>

t_list	*tokenize_line(char *line);
t_list	*expand_tokens(t_list *tokens);
int		is_grammar_correct(t_list *tokens);
t_list	*tokens_to_commands(t_list *tokens);

static t_list	*line_to_tokens(char *line)
{
	t_list	*tokens;
	t_list	*expanded_tokens;

	tokens = tokenize_line(line);
	if (tokens == NULL)
		return (NULL);
	expanded_tokens = expand_tokens(tokens);
	ft_lstclear(&tokens, free_token);
	if (expanded_tokens == NULL)
		return (NULL);
	return (expanded_tokens);
}

// return pipeline of commands
t_list	*parse_line(char *line, int *parse_status)
{
	t_list	*commands;
	t_list	*tokens;

	tokens = line_to_tokens(line);
	if (tokens == NULL)
	{
		*parse_status = ENOMEM;
		return (NULL);
	}
	if (!is_grammar_correct(tokens))
	{
		ft_lstclear(&tokens, free_token);
		*parse_status = EINVAL;
		return (NULL);
	}
	commands = tokens_to_commands(tokens);
	ft_lstclear(&tokens, free_token);
	if (commands == NULL)
	{
		*parse_status = ENOMEM;
		return (NULL);
	}
	*parse_status = SUCCESS;
	return (commands);
}
