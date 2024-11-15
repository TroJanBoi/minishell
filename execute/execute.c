/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:23:43 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/11/15 21:25:26 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	ft_err(char *txt)
{
	perror(txt);
	exit(EXIT_FAILURE);
}

void    execute(char **cmd, t_list *envp)
{
	char		*path;

	if (check_backslash(cmd[0]) == SUCCESS)
	{
		if (check_path(cmd[0]) == SUCCESS)
			path = ft_strdup(cmd[0]);
		else
		{
			perror(cmd[0]);
			exit(EXIT_FAILURE);
		}
	}
	path = find_path("PATH", envp, cmd[0]);
	// printf("%sPATH : %s%s\n",RED, path, RESET);
	if (execve(path, cmd, envp->content) == -1) // TODO: insert sub-shell builtin logic here
	{
		dprintf(2, "%s: command not found\n", cmd[0]);
		exit(EXIT_FAILURE);
	}
}

void	ft_childprocess(t_list *cmd_lst, int *prev_fd, t_shell_data *envp)
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
		handle_redirection_input(cmd_lst);
		handle_redirection_output(cmd_lst);
	}
	execute(cmd->command->argv, envp->env_var_list);

}

void	sub_execute(t_list *cmd_lst, t_shell_data *envp)
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
t_exit_status	main_execute(t_list *commands, t_shell_data *envp)
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
	// dprintf(2, "Exit status : %d\n", exit_status);
	// free_execute_command_list(&execute_command_list);
	// printf("%sEnd of execute%s\n", GREEN, RESET);
	return (exit_status);
}
