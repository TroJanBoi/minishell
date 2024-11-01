/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:33:45 by nteechar          #+#    #+#             */
/*   Updated: 2024/10/25 18:02:08 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

// print current working directory
void	builtin_pwd(t_command *command, t_shell_data *data)
{
	char	*path;

	path = getcwd(NULL, 0);
	if (path == NULL)
	{
		ft_putstr_fd("builtin_pwd: getcwd\n", STDERR_FILENO);
		data->exit_status = EXIT_FAILURE;
		return ;
	}
	ft_printf("%s\n", path);
	data->exit_status = EXIT_SUCCESS;
}
