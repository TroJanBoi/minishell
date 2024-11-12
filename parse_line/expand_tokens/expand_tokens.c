/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:59:43 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/07 18:43:28 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../token/token.h"

t_token	*expand_word_token(t_token *token);

static void	*expand_token(void *content)
{
	t_token	*token;
	t_token	*expanded_token;

	token = content;
	if (token->type == WORD)
		expanded_token = expand_word_token(token);
	else
		expanded_token = copy_token(token);
	if (expanded_token == NULL)
		return (NULL);
	return (expanded_token);
}

// input: tokenized line
// create a new chain of expanded WORD tokens
t_list	*expand_tokens(t_list *tokens)
{
	t_list	*expanded_tokens;

	expanded_tokens = ft_lstmap(tokens, expand_token, free_token);
	if (expanded_tokens == NULL)
		return (NULL);
	return (expanded_tokens);
}
