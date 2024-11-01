/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:12:57 by nteechar          #+#    #+#             */
/*   Updated: 2024/10/25 16:27:24 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/libft.h"
#include "env_var.h"

t_env_var	*process_key_value_line(char *line)
{
	t_env_var	*var;
	size_t		key_length;
	size_t		value_length;

	var = malloc(sizeof(t_env_var));
	if (var == NULL)
		return (NULL);
	key_length = ft_strchr(line, '=') - line;
	var->key = ft_substr(line, 0, key_length);
	if (var->key == NULL)
	{
		free(var);
		return (NULL);
	}
	value_length = ft_strchr(line, '\0') - ft_strchr(line, '=');
	var->value = ft_substr(line, key_length + 1, value_length);
	if (var->value == NULL)
	{
		free(var->value);
		free(var);
		return (NULL);
	}
	return (var);
}

void	free_env_var(void *var)
{
	t_env_var	*var_;

	var_ = var;
	free(var_->key);
	free(var_->value);
	free(var_);
}
