/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_execute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:23:43 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/10/03 00:43:28 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static t_exe	*init_execute(t_command *commands)
{
	t_exe	*cmd;

	cmd = malloc(sizeof(t_exe));
	if (!cmd)
		return (FALSE);
	cmd->command = commands;
    cmd->fd_in = -1;
    cmd->fd_out = -1;
    cmd->fd[0] = -1;
    cmd->fd[1] = -1;
    cmd->next = NULL;
	return (cmd);
}

void			append_exe(t_exe **head, t_command *command)
{
	t_exe	*new_cmd;
	t_exe	*temp;

	new_cmd = init_execute(command);
	if (!new_cmd)
		return ;
	if (*head == NULL)
	{
		*head = new_cmd;
	}
	else
	{
		temp = *head;
		while (temp->next)
			temp = temp->next;
		temp->next = new_cmd;
	}
}

void print_commands_exe(t_exe *exe_list)
{
    while (exe_list)
    {
        t_command *command = exe_list->command;
        printf("Command: ");
        print_string_arr(command->argv, "command->argv");
        print_tokens(command->redirs, "command->redirs");
        exe_list = exe_list->next;
	}
}

void execute(t_list *commands, char **envp)
{
    printf("%sStart execute%s\n", GREEN, RESET);
    t_exe		*cmd_list;
    t_command	*command;
	t_token		*token;

	cmd_list = NULL;
    while (commands)
    {
        command = (t_command *)commands->content;
        append_exe(&cmd_list, command);
        if (command->redirs)
        {
            // token = (t_token *)command->redirs->content;
            if (check_file(command->redirs) == FALSE)
            {
                perror(RED"File Filed"RESET);
                return ;
            }
        }
        commands = commands->next;
    }
    print_commands_exe(cmd_list); // debugging
    free_exe_list(cmd_list);
    printf("%sEnd of execute%s\n", GREEN, RESET);
}
