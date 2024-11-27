/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:23:43 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/11/20 20:00:38 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	ft_childprocess(t_list *cmd_lst, int *prev_fd, t_shell_data *envp);
int		wait_for_all_processes(t_list *cmd_lst);
void	ft_parentprocess(t_list *cmd_lst, int *prev_fd, t_execute *cmd);

void	sub_execute(t_list *cmd_lst, t_shell_data *envp)
{
	int			prev_fd;
	t_execute	*cmd;

	prev_fd = -1;
	cmd = cmd_lst->content;
	if (s_builtin(cmd_lst, cmd, envp) == SUCCESS)
		return ;
	while (cmd_lst)
	{
		cmd = cmd_lst->content;
		if (cmd->command->argv)
		{
			if (cmd_lst->next && pipe(cmd->pipe_fds) == -1)
				exit(EXIT_FAILURE);
			cmd->pid = fork();
			if (cmd->pid < 0)
				exit(EXIT_FAILURE);
			if (cmd->pid == 0)
				ft_childprocess(cmd_lst, &prev_fd, envp);
			else
				ft_parentprocess(cmd_lst, &prev_fd, cmd);
		}
		cmd_lst = cmd_lst->next;
	}
}

t_exit_status	main_execute(t_list *commands, t_shell_data *envp)
{
	int		exit_status;
	t_list	*execute_command_list;

	execute_command_list = init_execute_command_list(commands);
	if (execute_command_list == NULL)
		return (ERROR);
	run_heredocs(execute_command_list);
	sub_execute(execute_command_list, envp);
	exit_status = wait_for_all_processes(execute_command_list);
	free_execute_command_list(&execute_command_list);
	return (exit_status);
}
