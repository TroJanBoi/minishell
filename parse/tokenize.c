/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 18:04:16 by nteechar          #+#    #+#             */
/*   Updated: 2024/09/03 18:09:08 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

// return dynamically allocated string
char	*get_token_str(char *line)
{
	char	*str;
	int		i;

	if (line[0] == '>' && line[1] == '>')
		return (ft_strdup(">>"));
	if (line[0] == '>')
		return (ft_strdup(">"));
	if (line[0] == '<' && line[1] == '<')
		return (ft_strdup("<<"));
	if (line[0] == '<')
		return (ft_strdup("<"));
	if (line[0] == '|')
		return (ft_strdup("|"));
	i = 0;
	while (line[i] != '\0' && line[i] != '>' && line[i] != '<'
		&& line[i] != '|' && line[i] != ' ' && line[i] != '\t')
		i++;
	return (ft_substr(line, 0, i));
}

t_token_type	get_token_type(char *line)
{
	if (line[0] == '>' && line[1] == '>')
		return (REDIR_APPEND);
	if (line[0] == '>')
		return (REDIR_OUT);
	if (line[0] == '<' && line[1] == '<')
		return (HEREDOC);
	if (line[0] == '<')
		return (REDIR_IN);
	if (line[0] == '|')
		return (PIPE);
	return (WORD);
}

t_list	*get_token(char *line)
{
	t_list	*token;
	t_token	*content;

	token = malloc(sizeof(t_token));
	if (token == NULL)
		return (NULL);
	content = malloc(sizeof(t_token));
	if (content == NULL) {
		// clean up
	}
	//ft_printf("getting token str\n");
	content->str = get_token_str(line);
	if (content->str == NULL)
	{
		// clean up
	}
	//ft_printf("getting token type\n");
	content->type = get_token_type(line);
	token->content = content;
	return (token);
}

// return a linked list, where each node->content is of type (t_token *)
t_list	*tokenize(char *line)
{
	t_list	*tokens;
	t_list	*token;

	tokens = NULL;
	while (1)
	{
		while (*line == ' ' || *line == '\t')
			line++;
		if (*line == '\0')
			break ;
		//ft_printf("currently: %s\n", line);
		token = get_token(line);  // a node
		if (token == NULL)
		{
			// clean up
			return (NULL);
		}
		line += ft_strlen(((t_token *) token->content)->str);
		ft_lstadd_back(&tokens, token);
	}
	return (tokens);
}
