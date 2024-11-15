/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 02:14:34 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/11/15 02:14:45 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

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
