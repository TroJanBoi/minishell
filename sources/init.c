/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:43:04 by nteechar          #+#    #+#             */
/*   Updated: 2024/10/25 18:02:08 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static t_list	*envp_to_linked_list(char **envp)
{
	t_list		*list;
	t_env_var	*var;

	list = NULL;
	while (*envp)
	{
		var = process_key_value_line(*envp);
		if (var == NULL)
		{
			ft_lstclear(&list, free_env_var);
			return (NULL);
		}
		if (ft_lstnew_add_back(&list, var) == NULL)
		{
			ft_lstclear(&list, free_env_var);
			return (NULL);
		}
		envp++;
	}
	return (list);
}

int	init(t_shell_data *data, char **envp)
{
	setup_signal();
	data->is_running = TRUE;
	data->exit_status = EXIT_SUCCESS;
	data->env_vars = envp_to_linked_list(envp);
	if (data->env_vars == NULL)
		return (ERROR);
	return (SUCCESS);
}
