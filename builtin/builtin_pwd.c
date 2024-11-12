/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:33:45 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/12 12:00:32 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "builtin.h"

#define AS_BIG_AS_NECESSARY 0

// print current working directory
int	builtin_pwd(int argc, char **argv)
{
	char	*path;

	(void) argc;
	(void) argv;
	path = getcwd(NULL, AS_BIG_AS_NECESSARY);
	if (path == NULL)
	{
		ft_putstr_fd("builtin_pwd: getcwd\n", STDERR_FILENO);
		// data->exit_status = EXIT_FAILURE;
		return (ERROR);
	}
	ft_printf("%s\n", path);
	free(path);
	// data->exit_status = EXIT_SUCCESS;
	return (SUCCESS);
}
