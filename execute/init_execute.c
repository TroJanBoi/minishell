/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_execute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:23:43 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/10/16 11:59:03 by pesrisaw         ###   ########.fr       */
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
		*head = new_cmd;
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

void	ft_childprocess(t_exe *cmd_lst, char **envp)
{
	printf("%s |%s| %s\n", RED, cmd_lst->command->argv[0], RESET);
	while (cmd_lst)
	{
		if (cmd_lst->command->redirs)
		{
			printf("%s\n", (char *)cmd_lst->command->redirs->content);
		}
		cmd_lst = cmd_lst->next;
	}
	printf("sucess\n");
}

void	sub_execute(t_exe *cmd_lst, char **envp)
{
	printf("%sstart-sub_execute%s\n", YELLOW, RESET);
	while (cmd_lst)
	{
		if (cmd_lst->command->argv)
		{
			if (cmd_lst->next && pipe(cmd_lst->fd) == -1)
			{
				perror("pipe failed");
				exit(EXIT_FAILURE);
			}
			cmd_lst->pid = fork();
			if (cmd_lst->pid < 0)
			{
				perror("fork failed");
				exit(EXIT_FAILURE);
			}
			if (cmd_lst->pid == 0)
				ft_childprocess(cmd_lst, envp);
			else
				wait(&cmd_lst->pid);
		}
		cmd_lst = cmd_lst->next;
	}
	printf("%send-sub_execute%s\n", YELLOW, RESET);
}

void	execute(t_list *commands, char **envp)
{
    printf("%sStart execute%s\n", GREEN, RESET);
    t_exe		*cmd_list;
    t_command	*command;
	t_token		*token;

	cmd_list = NULL;
	if (check_file(commands) == FALSE)
	{
		printf("%s Fail checkfile %s\n", RED, RESET);
		return ;
	}
    while (commands)
    {
        command = (t_command *)commands->content;
        append_exe(&cmd_list, command);
        commands = commands->next;
	}
    sub_execute(cmd_list, envp);
	// free_exe_list(cmd_list);
    printf("%sEnd of execute%s\n", GREEN, RESET);
}
