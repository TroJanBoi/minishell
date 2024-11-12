/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:34:18 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/12 11:22:38 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "builtin.h"
#include "../parse_line/command/command.h"

// exit minishell
// command_list == NULL to exit immediately
void	builtin_exit(t_list *command_list, t_shell_data *data)
{
	if (command_list && ((t_command *) command_list)->argc > 1)
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", STDERR_FILENO);
		data->exit_status = EXIT_FAILURE;
		return ;
	}
	// printf("exit\n");
	free_shell_data(data);
	exit(data->exit_status);
}
