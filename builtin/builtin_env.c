/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:34:10 by nteechar          #+#    #+#             */
/*   Updated: 2024/10/25 18:12:27 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

// print all environment variables
void	builtin_env(t_command *command, t_shell_data *data)
{
	t_list		*node;
	t_env_var	*env_var;

	node = data->env_vars;
	while (node)
	{
		env_var = node->content;
		ft_printf("%s=%s\n", env_var->key, env_var->value);
		node = node->next;
	}
	data->exit_status = EXIT_SUCCESS;
}
