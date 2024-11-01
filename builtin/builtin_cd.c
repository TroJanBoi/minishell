/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:18:48 by nteechar          #+#    #+#             */
/*   Updated: 2024/10/29 17:40:47 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static void	handle_many_inputs(t_shell_data *data)
{
	ft_putendl_fd("minishell: cd: too many arguments", STDERR_FILENO);
	data->exit_status = EXIT_FAILURE;
}

static char	*get_path(t_command *command, t_shell_data *data)
{
	char	*path;

	if (command->argc == 1)
	{
		path = getenv("HOME");
		if (path == NULL)
		{
			ft_putstr_fd("minishell: cd: HOME not set\n", STDERR_FILENO);
			data->exit_status = EXIT_FAILURE;
			return (NULL);
		}
	}
	else
		path = command->argv[1];
	return (path);
}

static void	change_directory(char *path, t_shell_data *data)
{
	if (chdir(path) < SUCCESS)
	{
		ft_putstr_fd("minishell: cd: ", STDERR_FILENO);
		ft_putstr_fd(path, STDERR_FILENO);
		ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
		data->exit_status = EXIT_FAILURE;
	}
	else
		data->exit_status = EXIT_SUCCESS;
}

void	builtin_cd(t_command *command, t_shell_data *data)
{
	char	*path;

	if (command->argc >= 3)
	{
		handle_many_inputs(data);
		return ;
	}
	path = get_path(command, data);
	if (path == NULL)
		return ;
	change_directory(path, data);
}
