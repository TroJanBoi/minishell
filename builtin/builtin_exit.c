/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:34:18 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/27 15:14:16 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include "../libft/libft.h"
#include "../parser/parse_line.h"
#include "../setup/setup.h"
#include "builtin.h"

// exit minishell
// command_list == NULL to exit immediately
// set data->exit_status to ERROR if too many arguments
void	builtin_exit(int argc, char **argv, t_shell_data *data)
{
	int	exit_status;

	if (argc > 2)
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", STDERR_FILENO);
		data->exit_status = ERROR;
		return ;
	}
	if (argc == 2)
		exit_status = ft_atoi(argv[1]);
	else
		exit_status = data->exit_status;
	free_shell_data(data);
	restore_terminal_settings();
	exit(exit_status);
}
