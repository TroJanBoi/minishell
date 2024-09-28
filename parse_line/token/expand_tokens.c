/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:59:43 by nteechar          #+#    #+#             */
/*   Updated: 2024/09/23 16:10:46 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse_line.h"

static t_list	*tokenize_word(char *word)
{
	t_list	*tokens;

	tokens = NULL;
	return (tokens);
}

static char	*expand_word(char *word)
{
	char	*new_word;

	// tokenize
	// expand where applicable
	// return expanded word
	new_word = NULL;
	return (new_word);
}

// create a new chain of expanded WORD tokens 
// free old *tokens
// assign new chain to *tokens
t_list	*expand_tokens(t_list *tokens)
{
	t_list	*expanded_tokens;
	t_list	*node;
	t_token	*token;
	char	*str;

	expanded_tokens = NULL;
	while (tokens)
	{
		token = tokens->content;
		if (token->type == WORD)
		{
			str = expand_word(token->str);
			if (str == NULL)
			{
				// clean up
				return (NULL);
			}
		}
		else
			str = token->str;
		t_token	*new_token = create_token(str, token->type);
		if (new_token == NULL || ft_lstnew_add_back(&expanded_tokens, new_token) == NULL)
		{
			ft_lstclear(&expanded_tokens, free_token);
			return (NULL);
		}
		tokens = tokens->next;
	}
	return (expanded_tokens);
}
