/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:26:18 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/12 14:57:41 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "../libft/libft.h"
#include "parse_line.h"

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
t_list	*parse_line(char *line, t_shell_data *data)
{
	t_list	*commands;
	t_list	*tokens;

	tokens = line_to_tokens(line);
	if (tokens == NULL)
	{
		data->exit_status = ENOMEM;
		return (NULL);
	}
	if (!is_grammar_correct(tokens))
	{
		ft_lstclear(&tokens, free_token);
		data->exit_status = EINVAL;
		return (NULL);
	}
	commands = tokens_to_commands(tokens);
	ft_lstclear(&tokens, free_token);
	if (commands == NULL)
	{
		data->exit_status = ENOMEM;
		return (NULL);
	}
	data->exit_status = SUCCESS;
	return (commands);
}
