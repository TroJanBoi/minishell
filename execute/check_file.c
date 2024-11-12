/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 21:46:02 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/11/12 12:30:43 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

// done, DEPENDENCY: edit parsing module to output combined redir tokens

int	sub_check_file(t_list *redirs)
{
	t_token		*token;

	while (redirs->content)
	{
		token = redirs->content;
		if (token->type == INFILE)
		{
			// dprintf(2, GREEN"success type open file\n"RESET);
			redirs = redirs->next;
			token = redirs->content;
			if (token->type == WORD)
			{
				if (access(token->str, R_OK) == 0 \
					|| access(token->str, R_OK | W_OK) == 0)
					return (SUCCESS);
				else
				{
					perror(token->str);
					return (ERROR);
				}
			}
		}
		redirs = redirs->next;
	}
	return (SUCCESS);
}

int	check_file(t_list *command_list)
{
	int			status;
	t_command	*cmd;

	status = SUCCESS;
	while (command_list)
	{
		cmd = command_list->content;
		if (cmd->redirs)
			status = sub_check_file(cmd->redirs);
		command_list = command_list->next;
	}
	if (status) dprintf(2, YELLOW"status : SUCCESS\n"RESET);
	else dprintf(2, YELLOW"status : ERROR\n"RESET);
	return (status);
}
