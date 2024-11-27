/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chop_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:23:40 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/17 01:05:59 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../tokenize/token.h"

static t_subtoken_type	get_type(char *word)
{
	if (*word == '\'')
		return (SINGLE_QUOTE);
	if (*word == '\"')
		return (DOUBLE_QUOTE);
	if (*word == '$')
	{
		if (word[1] == '?')
			return (EXIT_STATUS);
		return (VARIABLE);
	}
	return (NORMAL);
}

static char	*extract_substring(char *word, t_subtoken_type type)
{
	int	i;

	i = 0;
	if (type == SINGLE_QUOTE || type == DOUBLE_QUOTE)
		i++;
	else if (type == VARIABLE)
	{
		i++;
		while (ft_isalnum(word[i]))
			i++;
	}
	else if (type == EXIT_STATUS)
		i += 2;
	else
	{
		while (word[i] && !ft_isinset(word[i], "\'\"$", 3))
			i++;
	}
	return (ft_substr(word, 0, i));
}

// word is guaruntee'd to not have whitespaces outside of quotes

// Types
// - quotes (could be either ' or ")
// - environment variables ($VAR)
// - normal string

// whitespaces (inside quotes) is treates as 
// a normal char, grouped with normal string
t_list	*chop_word(char *word)
{
	t_list			*subtokens;
	t_subtoken_type	type;
	char			*str;
	t_token			*subtoken;

	subtokens = NULL;
	while (*word)
	{
		type = get_type(word);
		str = extract_substring(word, type);
		subtoken = create_token(str, type);
		word += ft_strlen(str);
		free(str);
		if (subtoken == NULL)
		{
			ft_lstclear(&subtokens, free);
			return (NULL);
		}
		if (!ft_lstnew_add_back(&subtokens, subtoken))
		{
			free(subtoken);
			ft_lstclear(&subtokens, free);
			return (NULL);
		}
	}
	return (subtokens);
}
