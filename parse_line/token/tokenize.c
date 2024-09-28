/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:45:22 by nteechar          #+#    #+#             */
/*   Updated: 2024/09/20 16:48:18 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse_line.h"

// part of get_token_str function
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
			else if (ft_isinset(line[length], " \t<>|"))
				break ;
		}
		length++;
	}
	return (ft_substr(line, 0, length));
}

// part of get_token function
static int	get_token_type(char *line)
{
	if (ft_strncmp(line, ">>", 2) == 0)
		return (APPEND);
	if (ft_strncmp(line, ">", 1) == 0)
		return (OUTFILE);
	if (ft_strncmp(line, "<<", 2) == 0)
		return (HEREDOC);
	if (ft_strncmp(line, "<", 1) == 0)
		return (INFILE);
	if (ft_strncmp(line, "|", 1) == 0)
		return (PIPE);
	return (WORD);
}

// part of get_token function
static char	*get_token_str(char *line, int type)
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

static t_token	*get_token(char *line)
{
	int		type;
	char	*str;
	t_token	*token;

	type = get_token_type(line);
	str = get_token_str(line, type);
	if (str == NULL)
		return (NULL);
	token = create_token(str, type);
	free(str);
	if (token == NULL)
		return (NULL);
	return (token);
}

t_list	*tokenize(char *line)
{
	t_list	*tokens;
	t_token	*token;

	tokens = NULL;
	while (1)
	{
		while (*line == ' ' || *line == '\t')
			line++;
		if (*line == '\0')
			break ;
		token = get_token(line);
		if (token == NULL)
		{
			ft_lstclear(&tokens, free_token);
			return (NULL);
		}
		if (ft_lstnew_add_back(&tokens, token) == NULL)
		{
			free(token);
			ft_lstclear(&tokens, free_token);
			return (NULL);
		}
		line += ft_strlen(token->str);
	}
	return (tokens);
}
