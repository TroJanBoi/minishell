/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:39:36 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/07 18:43:10 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../token/token.h"

static char	*get_word(char *line)
{
	size_t	length;
	int		is_inside_quotes;

	length = 0;
	is_inside_quotes = FALSE;
	while (line[length] != '\0')
	{
		if (is_inside_quotes)
		{
			if (line[length] == '\'' || line[length] == '\"')
				is_inside_quotes = FALSE;
		}
		else
		{
			if (line[length] == '\'' || line[length] == '\"')
				is_inside_quotes = TRUE;
			else if (ft_isinset(line[length], " \t<>|", 5))
				break ;
		}
		length++;
	}
	return (ft_substr(line, 0, length));
}

char	*get_token_str(char *line, t_token_type type)
{
	if (type == APPEND)
		return (ft_strdup(">>"));
	if (type == OUTFILE)
		return (ft_strdup(">"));
	if (type == HEREDOC)
		return (ft_strdup("<<"));
	if (type == INFILE)
		return (ft_strdup("<"));
	if (type == PIPE)
		return (ft_strdup("|"));
	return (get_word(line));
}
