/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_execute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:23:43 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/10/16 22:14:41 by pesrisaw         ###   ########.fr       */
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

void	open_lastfile(t_exe *cmd_lst)
{
	t_list *redir;
	t_token *file;
	
	redir = cmd_lst->command->redirs;
	while (redir->content)
	{
		file = (t_token *)redir->content;
		if (file->type == WORD)
		{
			cmd_lst->fd_in = open(file->str, O_RDONLY);
			if (cmd_lst->fd_in == -1)
			{
				perror(file->str);
				return ;
			}
		}
		redir = redir->next;
	}
	dup2(cmd_lst->fd_in, STDIN_FILENO);
	close(cmd_lst->fd_in);
}

void    ft_childprocess(t_exe *cmd_lst, char **envp, int *prev_fd)
{
	if (cmd_lst->next)
	{
		dup2(cmd_lst->fd[1], STDOUT_FILENO);
		close(cmd_lst->fd[1]);
	}
	if (*prev_fd != -1)
	{
		dup2(*prev_fd, STDIN_FILENO);  // Redirect input from previous pipe
		close(*prev_fd);
	}
	if (cmd_lst->command->redirs->content)
		open_lastfile(cmd_lst);
	if (execvp(cmd_lst->command->argv[0], cmd_lst->command->argv) == -1)
		ft_err(cmd_lst->command->argv[0]);
}

void sub_execute(t_exe *cmd_lst, char **envp)
{
	int		prev_fd;
	t_exe	*current;

	prev_fd = -1;
	current = cmd_lst;
	while (cmd_lst)
	{
		if (cmd_lst->command->argv)
		{
			if (cmd_lst->next && pipe(cmd_lst->fd) == -1)
				ft_err("pipe failed");
			cmd_lst->pid = fork();
			if (cmd_lst->pid < 0)
				ft_err("fork failed");
			if (cmd_lst->pid == 0)
				ft_childprocess(cmd_lst, envp, &prev_fd);
			if (cmd_lst->next)
			{
				close(cmd_lst->fd[1]);
				prev_fd = cmd_lst->fd[0]; // set input from prevoius STDIN 
			}
		}
		cmd_lst = cmd_lst->next;
	}
	wait_allprocess(current);
}

void	execute(t_list *commands, char **envp)
{
	printf("%sStart execute%s\n", GREEN, RESET);
	t_exe		*cmd_list;
	t_command	*command;

	cmd_list = NULL;
	if (check_file(commands) == FALSE)
		return ;
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
