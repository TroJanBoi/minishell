/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:23:43 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/11/06 21:11:16 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	open_lastfile(t_exe *cmd_lst)
{
	t_list	*redir;
	t_token	*file;

	redir = cmd_lst->command->redirs;
	while (redir->content)
	{
		file = (t_token *)redir->content;
		if (file->type == 21)
		{
			redir = redir->next;
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
		}
		redir = redir->next;
	}
	dup2(cmd_lst->fd_in, STDIN_FILENO);
	close(cmd_lst->fd_in);
}

void	redir_output(t_token *file, t_exe *cmd_lst)
{
	if (file->type == WORD)
	{
		cmd_lst->fd_out = open(file->str, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (cmd_lst->fd_out == -1)
		{
			perror("failed file descriptor");
			exit(EXIT_FAILURE);
		}
		dup2(cmd_lst->fd_out, STDOUT_FILENO);
		close(cmd_lst->fd_out);
	}
}

void	redir_append(t_token *file, t_exe *cmd_lst)
{
	if (file->type == WORD)
	{
		cmd_lst->fd_out = open(file->str, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (cmd_lst->fd_out == -1)
		{
			perror("failed file descriptor");
			exit(EXIT_FAILURE);
		}
		dup2(cmd_lst->fd_out, STDOUT_FILENO);
		close(cmd_lst->fd_out);
	}
}

void	handle_redirection_output(t_exe *cmd_lst)
{
	t_list	*redir;
	t_token	*file;

	redir = cmd_lst->command->redirs;
	while (redir->content)
	{
		file = (t_token *)redir->content;
		if (file->type == 22)
		{
			dprintf(2, "%s>>>> Output Mode <<<<%s\n", YELLOW, RESET);
			redir = redir->next;
			file = (t_token *)redir->content;
			redir_output(file, cmd_lst);
		}
		else if (file->type == 24)
		{
			dprintf(2, "%s>>>> Append Mode <<<<%s\n", YELLOW, RESET);
			redir = redir->next;
			file = (t_token *)redir->content;
			redir_append(file, cmd_lst);
		}
		redir = redir->next;
	}
}

void	ft_childprocess(t_exe *cmd_lst, char **envp, int *prev_fd)
{
	if (cmd_lst->next)
	{
		dup2(cmd_lst->fd[1], STDOUT_FILENO);
		close(cmd_lst->fd[1]);
		close(cmd_lst->fd[0]);
	}
	if (*prev_fd != -1)
	{
		dup2(*prev_fd, STDIN_FILENO);
		close(*prev_fd);
	}
	if (cmd_lst->command->redirs->content)
	{
		open_lastfile(cmd_lst);
		handle_redirection_output(cmd_lst);
	}
	if (execvp(cmd_lst->command->argv[0], cmd_lst->command->argv) == -1)
	{
		perror(cmd_lst->command->argv[0]);
		exit(EXIT_FAILURE);
	}
}

void	wait_allprocess(t_exe *cmd_lst)
{
	while (cmd_lst)
	{
		if (cmd_lst->pid > 0)
			waitpid(cmd_lst->pid, NULL, 0);
		cmd_lst = cmd_lst->next;
	}
}

void	sub_execute(t_exe *cmd_lst, char **envp)
{
	int		prev_fd;
	t_exe	*cmd_lst_wait;

	prev_fd = -1;
	cmd_lst_wait = cmd_lst;
	while (cmd_lst)
	{
		if (cmd_lst->command->argv)
		{
			if (cmd_lst->next && pipe(cmd_lst->fd) == -1)
				ft_err("pipe failed");
			cmd_lst->pid = fork();
			dprintf(2, "pid->%d\n", cmd_lst->pid);
			if (cmd_lst->pid < 0)
				ft_err("fork failed");
			// child process
			if (cmd_lst->pid == 0)
				ft_childprocess(cmd_lst, envp, &prev_fd);
			// parent process
			if (cmd_lst->next) // ถ้ามีตัว command ตัวต่อไป
			{
				close(cmd_lst->fd[1]); // ปิด pipe out
				if (prev_fd != -1)
					close(prev_fd);
				prev_fd = cmd_lst->fd[0]; // pipe in ก้อนแรก ไปเก็บใน prev_fd  
			}
			else if (prev_fd != -1) // เงื่อนไขนี้สำหรับ command สุดท้าย
				close(prev_fd);
		}
		cmd_lst = cmd_lst->next;
	}
	wait_allprocess(cmd_lst_wait);
}

// free_exe_list(cmd_list);  (after executing ??)
void	execute(t_list *commands, char **envp)
{
	t_exe		*cmd_list;

	// printf("%sStart execute%s\n", GREEN, RESET);
	if (check_file(commands) == FALSE)
		return ;
	cmd_list = init_cmd_list(commands);
	print_commands_exe(cmd_list);
	sub_execute(cmd_list, envp);
	free_exe_list(cmd_list);
	// printf("%sEnd of execute%s\n", GREEN, RESET);
}
