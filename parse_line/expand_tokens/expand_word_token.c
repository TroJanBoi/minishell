/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_word_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:21:40 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/07 18:43:37 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../token/token.h"

t_list	*tokenize_word(char *word);
t_list	*expand_word_subtokens(t_list *subtokens);
char	*concatenate_word_subtokens(t_list *subtokens);

t_token	*expand_word_token(t_token *token)
{
	t_list	*word_subtokens;
	t_list	*expanded_word_subtokens;
	char	*new_word;
	t_token	*new_token;

	word_subtokens = tokenize_word(token->str);
	if (word_subtokens == NULL)
		return (NULL);
	expanded_word_subtokens = expand_word_subtokens(word_subtokens);
	ft_lstclear(&word_subtokens, free);
	if (expanded_word_subtokens == NULL)
		return (NULL);
	new_word = concatenate_word_subtokens(expanded_word_subtokens);
	ft_lstclear(&expanded_word_subtokens, free);
	if (new_word == NULL)
		return (NULL);
	new_token = create_token(new_word, WORD);
	free(new_word);
	if (new_token == NULL)
		return (NULL);
	return (new_token);
}
