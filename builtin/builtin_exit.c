/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:34:18 by nteechar          #+#    #+#             */
/*   Updated: 2024/10/29 17:58:36 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "../includes/minishell.h"

void	deinit(t_list **commands, t_shell_data *data)
{
	ft_lstclear(commands, free_command);
	ft_lstclear(&data->env_vars, free_env_var);
}

// exit minishell
void	builtin_exit(t_list *commands, t_shell_data *data)
{
	t_command	*command;

	command = commands->content;
	if (command->argc > 1)
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", STDERR_FILENO);
		data->exit_status = EXIT_FAILURE;
		return ;
	}
	printf("exit\n");
	deinit(&commands, data);
	exit(data->exit_status);
}
