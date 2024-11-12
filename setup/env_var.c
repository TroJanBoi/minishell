/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:12:57 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/11 16:33:45 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
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

// t_env_var	*process_key_value_line(char *line)
// {
// 	t_env_var	*var;
// 	size_t		key_length;
// 	size_t		value_length;

// 	var = malloc(sizeof(t_env_var));
// 	if (var == NULL)
// 		return (NULL);
// 	key_length = ft_strchr(line, '=') - line;
// 	var->key = ft_substr(line, 0, key_length);
// 	if (var->key == NULL)
// 	{
// 		free(var);
// 		return (NULL);
// 	}
// 	value_length = ft_strchr(line, '\0') - ft_strchr(line, '=');
// 	var->value = ft_substr(line, key_length + 1, value_length);
// 	if (var->value == NULL)
// 	{
// 		free(var->value);
// 		free(var);
// 		return (NULL);
// 	}
// 	return (var);
// }

// // may get ENOMEM
// t_list	*envp_to_env_var_list(char **envp)
// {
// 	t_list		*list;
// 	t_env_var	*var;

// 	list = NULL;
// 	while (*envp)
// 	{
// 		var = process_key_value_line(*envp);
// 		if (var == NULL)
// 		{
// 			ft_lstclear(&list, free_env_var);
// 			return (NULL);
// 		}
// 		if (ft_lstnew_add_back(&list, var) == NULL)
// 		{
// 			ft_lstclear(&list, free_env_var);
// 			return (NULL);
// 		}
// 		envp++;
// 	}
// 	return (list);
// }

