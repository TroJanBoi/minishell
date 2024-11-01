/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:33:51 by nteechar          #+#    #+#             */
/*   Updated: 2024/10/29 18:07:30 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// TODO: check memory safety! (Right now, there will likely be leaks!!!)
static void	handle_one_var(t_command *command, int i, t_shell_data *data)
{
	t_env_var	*var_arg;
	t_env_var	*var_envp;
	t_list		*envp;

	var_arg = process_key_value_line(command->argv[i]);
	if (var_arg == NULL)
	{
		data->exit_status = EXIT_FAILURE;
		return ;
	}
	envp = data->env_vars;
	while (envp)
	{
		var_envp = envp->content;
		if (ft_strcmp(var_arg->key, var_envp->key) == 0)
		{
			var_envp->value = ft_strdup(var_arg->value);
			free_env_var(var_arg);
			data->exit_status = EXIT_SUCCESS;
			return ;
		}
		envp = envp->next;
	}
	ft_lstnew_add_back(&data->env_vars, var_arg);
}

// set environment variable(s)
void	builtin_export(t_command *command, t_shell_data *data)
{
	int	i;

	i = 1;
	while (i < command->argc)
	{
		handle_one_var(command, i, data);
		i++;
	}
}
