/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:31:11 by nteechar          #+#    #+#             */
/*   Updated: 2024/10/25 18:02:08 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	builtin_echo(t_command *command, t_shell_data *data)
{
	int		put_newline;
	int		i;

	put_newline = TRUE;
	i = 1;
	if (i < command->argc)
	{
		while (i < command->argc && ft_strcmp(command->argv[i], "-n") == 0)
		{
			put_newline = FALSE;
			i++;
		}
		while (i < command->argc)
		{
			if (i == command->argc - 1)
				ft_printf("%s", command->argv[i]);
			else
				ft_printf("%s ", command->argv[i]);
			i++;
		}
	}
	if (put_newline)
		ft_printf("\n");
	data->exit_status = TRUE;
}
