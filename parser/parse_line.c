/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:26:18 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/27 14:10:18 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "../libft/libft.h"
#include "parse_line.h"

#define KEEP_PARSING TRUE
#define STOP FALSE

t_token_list	*tokenize_line(char *line);
void			expand_tokens(t_list **tokens, t_shell_data *data);

int				is_quote_closed(char *line);
int				is_grammar_correct(t_list *tokens);

t_command_list	*create_command_list(t_list *tokens);

static int	preliminary_check(char *line, t_shell_data *data)
{
	if (ft_strlen(line) == 0)
		return (STOP);
	else if (!is_quote_closed(line))
	{
		data->exit_status = EINVAL;
		return (STOP);
	}
	return (KEEP_PARSING);
}

static int	process_line_into_tokens(char *line, t_list	**tokens, \
	t_shell_data *data)
{
	*tokens = tokenize_line(line);
	if (*tokens == NULL)
	{
		data->exit_status = ENOMEM;
		return (STOP);
	}
	expand_tokens(tokens, data);
	if (*tokens == NULL)
	{
		data->exit_status = ENOMEM;
		return (STOP);
	}
	return (KEEP_PARSING);
}

// if syntax error: free tokens, and tell the parser to stop
static int	check_syntax(t_token_list **tokens, t_shell_data *data)
{
	if (is_grammar_correct(*tokens))
		return (KEEP_PARSING);
	else
	{
		ft_putstr_fd("minishell: syntax error\n", STDERR_FILENO);
		ft_lstclear(tokens, free_token);
		data->exit_status = EINVAL;
		return (STOP);
	}
}

// process line, check syntax (and set error_code accordingly)
// if syntax correct: set data->command_list = <parsed_commands>
// else: data->command_list = NULL
//
// assume result is SUCCESS unless find error afterward
t_command_list	*parse_line(char *line, t_shell_data *data)
{
	t_command_list	*commands;
	t_token_list	*tokens;

	data->exit_status = SUCCESS;
	if (preliminary_check(line, data) != KEEP_PARSING)
		return (NULL);
	if (process_line_into_tokens(line, &tokens, data) != KEEP_PARSING)
		return (NULL);
	if (check_syntax(&tokens, data) != KEEP_PARSING)
		return (NULL);
	commands = create_command_list(tokens);
	ft_lstclear(&tokens, free_token);
	if (commands == NULL)
	{
		data->exit_status = ENOMEM;
		return (NULL);
	}
	return (commands);
}
