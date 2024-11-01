/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:39:37 by nteechar          #+#    #+#             */
/*   Updated: 2024/10/16 16:49:09 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse_line.h"

// create malloc'd token
// - have malloc'd duplicate of str for token->str
// - have integer for token->type
// return NULL if malloc error
t_token	*create_token(char *str, t_token_type type)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (token == NULL)
		return (NULL);
	token->type = type;
	token->str = ft_strdup(str);
	if (token->str == NULL)
	{
		free(token);
		return (NULL);
	}
	return (token);
}

void	*copy_token(void *token)
{
	t_token	*token_;
	t_token	*new_token;

	token_ = token;
	new_token = create_token(token_->str, token_->type);
	if (new_token == NULL)
		return (NULL);
	return (new_token);
}

void	free_token(void *token)
{
	t_token	*token_;

	token_ = token;
	free(token_->str);
	free(token_);
}
