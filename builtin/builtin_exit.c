/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:34:18 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/27 17:12:21 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "builtin.h"
#include "../parse_line/parse_line.h"
#include "../execute/execute.h"
#include <readline/readline.h>

// exit minishell
// command_list == NULL to exit immediately
// set data->exit_status to ERROR if too many arguments
void	builtin_exit(t_command *command, t_shell_data *data)
{
	if (command->argc > 2)
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", STDERR_FILENO);
		data->exit_status = ERROR;
		return ;
	}
	rl_clear_history();
	free_shell_data(data);
	free_command(command);
	if (command->argc == 2)
		data->exit_status = ft_atoi(command->argv[1]);
	printf("exit\n");
	exit(data->exit_status);
}

// they are all the same, but gu run out of idea for the design
void	builtin_exit_0(t_shell_data *data)
{
	rl_clear_history();
	free_shell_data(data);
	printf("exit\n");
	exit(data->exit_status);
}

void	builtin_exit_2(t_list **cmd_lst, t_shell_data *data)
{
	t_command	*command;

	command = ((t_execute *)(*cmd_lst)->content)->command;
	if (command->argc > 2)
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", STDERR_FILENO);
		data->exit_status = ERROR;
		return ;
	}
	rl_clear_history();
	free_shell_data(data);
	if (cmd_lst)
		free_execute_command_list(cmd_lst);
	if (command->argc == 2)
		data->exit_status = ft_atoi(command->argv[1]);
	printf("exit\n");
	exit(data->exit_status);
}
