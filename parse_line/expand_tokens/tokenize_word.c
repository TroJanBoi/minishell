/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:23:40 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/07 18:43:41 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"

static char	*get_duplicate_substring(char *word)
{
	int	i;

	if (*word == '\'')
		return (ft_strdup("\'"));
	if (*word == '\"')
		return (ft_strdup("\""));
	i = 0;
	if (*word == '$')
	{
		i++;
		while (ft_isalnum(word[i]))
			i++;
	}
	else
	{
		while (word[i] != '\0' && !ft_isinset(word[i], "\'\"$\0", 4))
			i++;
	}
	return (ft_substr(word, 0, i));
}

// word is guarunteed to not have whitespaces outside of quotes

// Types
// - quotes (could be either ' or ")
// - environment variables ($VAR)
// - normal string

// whitespaces (inside quotes) is treates as 
// a normal char, grouped with normal string
t_list	*tokenize_word(char *word)
{
	t_list	*subtokens;
	char	*str;

	subtokens = NULL;
	while (*word)
	{
		str = get_duplicate_substring(word);
		if (str == NULL)
		{
			ft_lstclear(&subtokens, free);
			return (NULL);
		}
		if (ft_lstnew_add_back(&subtokens, str) == NULL)
		{
			free(str);
			ft_lstclear(&subtokens, free);
			return (NULL);
		}
		word += ft_strlen(str);
	}
	return (subtokens);
}
