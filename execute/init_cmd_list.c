/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:11:30 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/03 14:52:43 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static t_exe	*init_execute(t_command *commands)
{
	t_exe	*cmd;

	cmd = malloc(sizeof(t_exe));
	if (!cmd)
		return (NULL);
	cmd->command = commands;
	cmd->fd_in = -1;
	cmd->fd_out = -1;
	cmd->fd[0] = -1;
	cmd->fd[1] = -1;
	cmd->next = NULL;
	return (cmd);
}

// WARNING: TODO: MEMORY safety!!!
void	append_exe(t_exe **head, t_command *command)
{
	t_exe	*new_cmd;
	t_exe	*temp;

	new_cmd = init_execute(command);
	if (!new_cmd)
		return ;
	if (*head == NULL)
		*head = new_cmd;
	else
	{
		temp = *head;
		while (temp->next)
			temp = temp->next;
		temp->next = new_cmd;
	}
}

t_exe	*init_cmd_list(t_list *commands)
{
	t_exe		*cmd_list;
	t_command	*command;

	cmd_list = NULL;
	while (commands)
	{
		command = (t_command *)commands->content;
		append_exe(&cmd_list, command);
		commands = commands->next;
	}
	return (cmd_list);
}
