/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:34:03 by nteechar          #+#    #+#             */
/*   Updated: 2024/10/25 18:25:42 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static void	handle_one_var(t_command *command, int i, t_shell_data *data)
{
	t_list		*prev;
	t_list		*cur;
	t_env_var	*var;

	prev = NULL;
	cur = data->env_vars;
	while (cur)
	{
		var = cur->content;
		if (ft_strcmp(var->key, command->argv[i]) == 0)
		{
			if (prev)
				prev->next = cur->next;
			else
				data->env_vars = cur->next;
			ft_lstdelone(cur, free_env_var);
			break ;
		}
		prev = cur;
		cur = cur->next;
	}
}

// unset environment variable(s)
void	builtin_unset(t_command *command, t_shell_data *data)
{
	int	i;

	i = 1;
	while (i < command->argc)
	{
		handle_one_var(command, i, data);
		i++;
	}
}
