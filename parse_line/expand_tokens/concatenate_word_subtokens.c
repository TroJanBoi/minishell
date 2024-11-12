/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concatenate_word_subtokens.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:23:57 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/07 18:43:24 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"

static char	*malloc_word(t_list *subtokens)
{
	size_t	length;

	length = 0;
	while (subtokens)
	{
		length += ft_strlen(subtokens->content);
		subtokens = subtokens->next;
	}
	return (malloc(sizeof(char) * (length + 1)));
}

char	*concatenate_word_subtokens(t_list *subtokens)
{
	char	*word;
	size_t	word_length;
	char	*str;
	size_t	new_length;

	word = malloc_word(subtokens);
	if (word == NULL)
		return (NULL);
	word[0] = '\0';
	word_length = 0;
	while (subtokens)
	{
		str = subtokens->content;
		new_length = word_length + ft_strlen(str);
		if (ft_strlcat(word, str, new_length + 1) != new_length)
			ft_putendl_fd("concatenate_subtokens: ft_strlcat truncated", \
				STDERR_FILENO);
		word_length = new_length;
		subtokens = subtokens->next;
	}
	return (word);
}
