/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:12:57 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/20 17:51:43 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_var.h"

t_env_var	*create_env_var(char *key, char *value)
{
	t_env_var	*var;

	var = malloc(sizeof(t_env_var));
	if (var == NULL)
		return (NULL);
	var->key = ft_strdup(key);
	if (var->key == NULL)
	{
		free(var);
		return (NULL);
	}
	if (value)
		var->value = ft_strdup(value);
	else
		var->value = ft_strdup("");
	if (var->value == NULL)
	{
		free(var->value);
		free(var);
		return (NULL);
	}
	return (var);
}

void	free_env_var(void *env_var)
{
	t_env_var	*var;

	var = env_var;
	free(var->key);
	free(var->value);
	free(var);
}
