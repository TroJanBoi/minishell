/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:23:43 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/11/12 15:20:28 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	ft_err(char *txt)
{
	perror(txt);
	exit(EXIT_FAILURE);
}

void	open_lastfile(t_list *cmd_lst)
{
	t_list				*redirs;
	t_execute_command	*exe_cmd;

	t_token				*operator;
	t_token				*filename;

	exe_cmd = cmd_lst->content;
	redirs = exe_cmd->command->redirs;
	while (redirs->content)
	{
		operator = redirs->content;
		if (operator->type == INFILE)
		{
			redirs = redirs->next;
			filename = redirs->content;
			if (filename->type == WORD)
			{
				exe_cmd->fd_in = open(filename->str, O_RDONLY);
				if (exe_cmd->fd_in == -1)
				{
					perror(filename->str);
					return ;
				}
			}
		}
		redirs = redirs->next;
	}
	dup2(exe_cmd->fd_in, STDIN_FILENO);
	close(exe_cmd->fd_in);
}

void	redir_output_type_file(t_token *file, t_list *cmd_lst, int type)
{
	t_execute_command	*cmd;
	int 				mode;

	if (file->type != WORD)
		return ;
	if (type == APPEND)
		mode = O_WRONLY | O_CREAT | O_APPEND;
	else
		mode = O_WRONLY | O_CREAT | O_TRUNC;
	cmd = cmd_lst->content;
	cmd->fd_out = open(file->str, mode, 0644);
	if (cmd->fd_out == -1)
	{
		perror("failed file descriptor");
		exit(EXIT_FAILURE);
	}
	dup2(cmd->fd_out, STDOUT_FILENO);
	close(cmd->fd_out);
}

void	handle_redirection_output(t_list *cmd_lst)
{
	t_list				*redirs;
	t_token				*operator;
	t_token				*filename;
	t_execute_command	*exe_cmd;

	exe_cmd = cmd_lst->content;
	redirs = exe_cmd->command->redirs;
	while (redirs->content)
	{
		operator = redirs->content;
		if (operator->type == OUTFILE || operator->type == APPEND)
		{
			if (operator->type == OUTFILE) dprintf(2, "%s>>>> Output Mode <<<<%s\n", YELLOW, RESET);
			else dprintf(2, "%s>>>> Append Mode <<<<%s\n", YELLOW, RESET);

			redirs = redirs->next;
			filename = redirs->content;
			redir_output_type_file(filename, cmd_lst, operator->type);
		}
		redirs = redirs->next;
	}
}

void	ft_childprocess(t_list *cmd_lst, int *prev_fd, char **envp)
{
	t_execute_command	*cmd;

	cmd = cmd_lst->content;
	if (cmd_lst->next)
	{
		dup2(cmd->pipe_fds[1], STDOUT_FILENO);
		close(cmd->pipe_fds[1]);
		close(cmd->pipe_fds[0]);
	}
	if (*prev_fd != -1)
	{
		dup2(*prev_fd, STDIN_FILENO);
		close(*prev_fd);
	}
	if (cmd->command->redirs->content)
	{
		open_lastfile(cmd_lst);
		handle_redirection_output(cmd_lst);
	}
	if (execve(cmd->command->argv[0], cmd->command->argv, envp) == -1)  // TODO: insert sub-shell builtin logic here
	{
		dprintf(2, "execve error\n");
		perror(cmd->command->argv[0]);
		exit(EXIT_FAILURE);
	}
}

int	wait_allprocess(t_list *cmd_lst)
{
	int					exit_status;
	t_execute_command	*cmd;

	exit_status = SUCCESS;
	while (cmd_lst)
	{
		cmd = cmd_lst->content;
		if (cmd->pid > 0)
			waitpid(cmd->pid, NULL, 0);  // TODO: get exit_status from child process
		cmd_lst = cmd_lst->next;
	}
	return (exit_status);
}

void	sub_execute(t_list *cmd_lst, char **envp)
{
	int					prev_fd;
	t_execute_command	*cmd;

	prev_fd = -1;
	while (cmd_lst)
	{
		cmd = cmd_lst->content;
		if (cmd->command->argv)
		{
			if (cmd_lst->next && pipe(cmd->pipe_fds) == -1)
				ft_err("pipe failed");

			cmd->pid = fork();
			dprintf(2, "pid->%d\n", cmd->pid);
			if (cmd->pid < 0)
				ft_err("fork failed");
			
			// child process
			if (cmd->pid == 0)
				ft_childprocess(cmd_lst, &prev_fd, envp);  // TODO: replace envp with custom-envp
			
			// parent process
			if (cmd_lst->next) // ถ้ามีตัว command ตัวต่อไป
			{
				close(cmd->pipe_fds[1]); // ปิด pipe out
				if (prev_fd != -1)
					close(prev_fd);
				prev_fd = cmd->pipe_fds[0]; // pipe in ก้อนแรก ไปเก็บใน prev_fd  
			}
			else if (prev_fd != -1) // เงื่อนไขนี้สำหรับ command สุดท้าย
				close(prev_fd);
		}
		cmd_lst = cmd_lst->next;
	}
}

// free_exe_list(cmd_list);  (after executing ??)
int	execute(t_list *commands, char **envp)
{
	int		exit_status;
	t_list	*execute_command_list;

	// printf("%sStart execute%s\n", GREEN, RESET);
	
	if (check_file(commands) == ERROR)
		return (ERROR);
	execute_command_list = init_execute_command_list(commands);
	if (execute_command_list == NULL)
		return (ERROR);
		
	print_execute_commands(execute_command_list);
	
	sub_execute(execute_command_list, envp);
	exit_status = wait_allprocess(execute_command_list);
	
	// free_execute_command_list(&execute_command_list);
	
	// printf("%sEnd of execute%s\n", GREEN, RESET);
	return (exit_status);
}
