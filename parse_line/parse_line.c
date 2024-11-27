/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:26:18 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/17 03:26:47 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "../libft/libft.h"
#include "parse_line.h"

t_list	*tokenize_line(char *line);
void	expand_tokens(t_list **tokens, t_shell_data *data);
int		is_grammar_correct(t_list *tokens);
void	combine_redirs(t_list **tokens);
t_list	*create_command_list(t_list *tokens);

// return pipeline of commands
t_list	*parse_line(char *line, t_shell_data *data)
{
	t_list	*commands;
	t_list	*tokens;

	tokens = tokenize_line(line);
	if (tokens == NULL)
	{
		data->exit_status = ENOMEM;
		return (NULL);
	}
	expand_tokens(&tokens, data);
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
	// combine_redirs(&tokens);
	commands = create_command_list(tokens);
	if (commands == NULL)
	{
		data->exit_status = ENOMEM;
		return (NULL);
	}
	ft_lstclear(&tokens, free_token);
	data->exit_status = SUCCESS;
	return (commands);
}
