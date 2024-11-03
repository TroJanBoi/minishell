/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:23:43 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/11/03 18:01:34 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
int g_exit_status = 0;

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
		open_lastfile(cmd_lst);
	if (execvp(cmd_lst->command->argv[0], cmd_lst->command->argv) == -1)
	{
		perror(cmd_lst->command->argv[0]);
		exit(127);
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
				close(cmd_lst->fd[1]); // ปิด OUTPUT 
				if (prev_fd != -1) // 
					close(prev_fd);
				prev_fd = cmd_lst->fd[0]; 
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
