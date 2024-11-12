/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_cmd_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:11:30 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/12 15:20:40 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static void	*make_execute_command(void *command)
{
	t_execute_command	*cmd;

	cmd = malloc(sizeof(t_execute_command));
	if (cmd == NULL)
		return (NULL);
	cmd->command = command;
	cmd->fd_in = -1;
	cmd->fd_out = -1;
	cmd->pipe_fds[0] = -1;
	cmd->pipe_fds[1] = -1;
	return (cmd);
}

static void	free_execute_command(void *execute_command)
{
	t_execute_command	*cmd;

	cmd = execute_command;
	free_command(cmd->command);
	free(cmd);
}

t_list	*init_execute_command_list(t_list *commands)
{
	t_list	*execute_command_list;

	execute_command_list = ft_lstmap( \
		commands, make_execute_command, free_execute_command);
	if (execute_command_list == NULL)
		return (NULL);
	return (execute_command_list);
}

void	free_execute_command_list(t_list **execute_command_list)
{
	ft_lstclear(execute_command_list, free_execute_command);
}