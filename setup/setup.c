/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:43:04 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/11 17:00:39 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "../libft/libft.h"
#include "setup.h"

void	setup_signal(void);

t_shell_data	*create_shell_data(int argc, char **argv, char **envp)
{
	t_shell_data	*data;

	(void) argc;
	(void) argv;
	data = malloc(sizeof(t_shell_data));
	if (data == NULL)
		return (NULL);
	data->env_var_list = create_env_var_list(envp);
	if (data->env_var_list == NULL)
	{
		free(data);
		return (NULL);
	}
	data->exit_status = EXIT_SUCCESS;
	return (data);
}

void	free_shell_data(t_shell_data *data)
{
	free_env_var_list(&data->env_var_list);
	free(data);
}

t_shell_data	*init(int argc, char **argv, char **envp)
{
	t_shell_data	*data;

	setup_signal();
	data = create_shell_data(argc, argv, envp);
	if (data == NULL)
		return (NULL);
	return (data);
}
