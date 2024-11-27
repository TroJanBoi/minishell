/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:33:45 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/16 17:46:31 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "builtin.h"

#define AS_BIG_AS_NECESSARY 0

// print current working directory
t_exit_status	builtin_pwd(int argc, char **argv, t_shell_data *data)
{
	char	*path;

	(void) argc;
	(void) argv;
	(void) data;
	path = getcwd(NULL, AS_BIG_AS_NECESSARY);
	if (path == NULL)
	{
		ft_putstr_fd("builtin_pwd: getcwd\n", STDERR_FILENO);
		return (ERROR);
	}
	ft_printf("%s\n", path);
	free(path);
	return (SUCCESS);
}
