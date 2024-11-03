/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 21:46:02 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/11/03 14:55:09 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	sub_check_file(t_list *file)
{
	int			status;
	t_token		*token;

	status = TRUE;
	while (file->content)
	{
		token = (t_token *)file->content;
		if (token->type == 21)
		{
			dprintf(2, GREEN"success type open file\n"RESET);
			file = file->next;
			token = (t_token *)file->content;
			if (token->type == WORD)
			{
				if (access(token->str, R_OK) == 0 \
					|| access(token->str, R_OK | W_OK) == 0)
					status = TRUE;
				else
				{
					perror(token->str);
					status = FALSE;
					break ;
				}
			}
		}
		file = file->next;
	}
	return (status);
}

int	check_file(t_list *tokens)
{
	int			status;
	t_command	*cmd;
	t_list		*file;

	status = TRUE;
	while (tokens)
	{
		cmd = (t_command *)tokens->content;
		if (cmd->redirs != NULL)
		{
			file = (t_list *)cmd->redirs;
			status = sub_check_file(file);
		}
		tokens = tokens->next;
	}
	dprintf(2, YELLOW"status : %d\n"RESET, status);
	return (status);
}
