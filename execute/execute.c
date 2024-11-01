/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:23:43 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/10/29 18:24:39 by nteechar         ###   ########.fr       */
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

void	ft_childprocess(t_exe *cmd_lst, char **envp, int *prev_fd)
{
	if (cmd_lst->next)
	{
		dup2(cmd_lst->fd[1], STDOUT_FILENO);
		close(cmd_lst->fd[1]);
	}
	if (*prev_fd != -1)
	{
		dup2(*prev_fd, STDIN_FILENO); // Redirect input from previous pipe
		close(*prev_fd);
	}
	if (cmd_lst->command->redirs->content)
		open_lastfile(cmd_lst);
	if (execvp(cmd_lst->command->argv[0], cmd_lst->command->argv) == -1)
		ft_err(cmd_lst->command->argv[0]);
}

void	sub_execute(t_exe *cmd_lst, char **envp)
{
	int	prev_fd;

	prev_fd = -1;
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
			waitpid(cmd_lst->pid, NULL, 0);
		}
		cmd_lst = cmd_lst->next;
	}
}

// free_exe_list(cmd_list);  (after executing ??)
void	execute(t_list *commands, char **envp)
{
	t_exe		*cmd_list;

	printf("%sStart execute%s\n", GREEN, RESET);
	if (check_file(commands) == FALSE)
		return ;
	cmd_list = init_cmd_list(commands);
	sub_execute(cmd_list, envp);
	printf("%sEnd of execute%s\n", GREEN, RESET);
}
