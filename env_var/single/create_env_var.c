/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:46:57 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/25 16:47:05 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../env_var.h"

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
