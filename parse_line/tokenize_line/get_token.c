/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:46:22 by nteechar          #+#    #+#             */
/*   Updated: 2024/10/16 16:48:40 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse_line.h"

t_token_type	get_token_type(char *line);
char			*get_token_str(char *line, t_token_type type);

t_token	*get_token(char *line)
{
	t_token_type	type;
	char			*str;
	t_token			*token;

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
