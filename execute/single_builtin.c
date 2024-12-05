/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:32:21 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/12/02 17:30:18 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void			handle_redir_input_output(t_list *cmd_lst);
t_exit_status	p_execute_built(t_command *cmd, t_shell_data *data);
int				is_p_builtin_name(char *name);

int	s_builtin(t_list *cmd_lst, t_execute *cmd, t_shell_data *envp)
{
	if (ft_lstsize(cmd_lst) == 1 && cmd->command->argv[0] != NULL)
	{
		if (is_p_builtin_name(cmd->command->argv[0]))
		{
			if (cmd->command->redirs)
				handle_redir_input_output(cmd_lst);
			envp->exit_status = p_execute_built(cmd->command, envp);
			return (SUCCESS);
		}
	}
	return (ERROR);
}
