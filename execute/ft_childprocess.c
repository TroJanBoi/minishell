/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_childprocess.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 04:43:59 by nteechar          #+#    #+#             */
/*   Updated: 2024/12/05 14:11:07 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include <fcntl.h>
#include <unistd.h>

void	handle_redir_input_output(t_list *cmd_lst);

void	close_unused_fds(void)
{
	for (int fd = 3; fd < 1024; fd++) // ปิด fd ตั้งแต่ 3 ขึ้นไป
	{
		if (fcntl(fd, F_GETFD) != -1) // ตรวจสอบว่า fd ถูกเปิดหรือไม่
			close(fd); // ปิด fd ที่ไม่ต้องใช้
	}
}

void debug_fds(void)
{
	for (int fd = 0; fd < 1024; fd++)
	{
		if (fcntl(fd, F_GETFD) != -1)
			printf("FD %d is open\n", fd);
	}
}

static void	execute(char **cmd, t_list *env_var_list)
{
	char	*path;
	char	**envp;

	if (!cmd || !cmd[0])
		exit(ISSUE_PATH);
	if (ft_strchr(cmd[0], '/'))
	{
		if (access(cmd[0], X_OK) == SUCCESS)
			path = ft_strdup(cmd[0]);
		else
			return (command_not_found(cmd[0], STDERR_FILENO));
	}
	else
			path = find_path("PATH", env_var_list, cmd[0]);
	if (path == NULL)
		return (command_not_found(cmd[0], STDERR_FILENO));
	envp = get_envp_arr(env_var_list);
	if (envp == NULL)
	{
		ft_free_str_arr(envp, 0);
		exit(EXIT_FAILURE);
	}
	if (execve(path, cmd, envp) == -1)
	{
		free(path);
		ft_free_str_arr(envp, 0);
		exit(ISSUE_PATH);
	}
}

void	ft_childprocess(t_list *cmd_lst, int *prev_fd, t_shell_data *envp)
{
	t_execute	*cmd;

	cmd = cmd_lst->content;
	if (check_infiles(cmd->command->redirs) == ERROR)
		exit(EXIT_FAILURE);
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
	if (cmd->command->redirs)
		handle_redir_input_output(cmd_lst);
	if (is_builtin_name(cmd->command->argv[0]))
	{
		if (cmd->command)
			envp->exit_status = execute_builtin(cmd->command, envp);
		exit(envp->exit_status);
	}
	else
		execute(cmd->command->argv, envp->env_var_list);
}
