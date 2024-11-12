/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:47:13 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/07 18:42:42 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../token/token.h"

int	add_command(t_list **commands, t_list **temp_argv, t_list **temp_redirs);

static int	handle_word(t_list **temp_argv, t_list **tokens)
{
	t_token	*token;
	t_token	*new_token;

	token = (*tokens)->content;
	new_token = copy_token(token);
	if (new_token == NULL)
		return (ERROR);
	if (ft_lstnew_add_back(temp_argv, new_token) == NULL)
	{
		free_token(new_token);
		return (ERROR);
	}
	return (SUCCESS);
}

static int	handle_redir(t_list **temp_redirs, t_list **tokens)
{
	t_token	*token;
	t_token	*new_token;
	int		i;

	i = 0;
	while (1)
	{
		token = (*tokens)->content;
		new_token = copy_token(token);
		if (new_token == NULL)
			return (ERROR);
		if (ft_lstnew_add_back(temp_redirs, new_token) == NULL)
		{
			free_token(new_token);
			return (ERROR);
		}
		if (i == 1)
			break ;
		*tokens = (*tokens)->next;
		i++;
	}
	return (SUCCESS);
}

int	handle_tokens(t_list **tokens, t_list **commands, t_list **temp_argv,
	t_list **temp_redirs)
{
	t_token	*token;
	int		handle_status;

	token = (*tokens)->content;
	if (token->type == PIPE)
		handle_status = add_command(commands, temp_argv, temp_redirs);
	else if (token->type == WORD)
		handle_status = handle_word(temp_argv, tokens);
	else
		handle_status = handle_redir(temp_redirs, tokens);
	*tokens = (*tokens)->next;
	return (handle_status);
}
