/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_grammar_correct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:05:28 by nteechar          #+#    #+#             */
/*   Updated: 2024/09/20 16:55:46 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_line.h"

static int	is_redir_correct(t_list **tokens, int *have_command)
{
	t_token	*next_token;

	if ((*tokens)->next == NULL)
		return (FALSE);
	next_token = (*tokens)->next->content;
	if (next_token->type != WORD)
		return (FALSE);
	*tokens = (*tokens)->next;
	*have_command = TRUE;
	return (TRUE);
}

// BNF:
// <commands> = <command> || <command> PIPE <commands>
// <command> = WORD || <redir> || WORD <command> || <redir> <command>
// <redir> = INFILE WORD || OUTFILE WORD || HEREDOC WORD || APPEND WORD
int	is_grammar_correct(t_list *tokens)
{
	t_token	*token;
	int		have_command;

	have_command = FALSE;
	while (tokens)
	{
		token = tokens->content;
		if (token->type == PIPE)
		{
			if (have_command == FALSE)
				return (FALSE);
			have_command = FALSE;
		}
		else if (token->type == WORD)
			have_command = TRUE;
		else
		{
			if (!is_redir_correct(&tokens, &have_command))
				return (FALSE);
		}
		tokens = tokens->next;
	}
	return (TRUE);
}
