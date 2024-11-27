/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env_var_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:05:43 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/16 22:56:48 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/libft.h"
#include "env_var.h"

char	**split_env_var_line(char *env_var_line)
{
	char	**key_value_pair;
	char	*first_equal_sign;
	size_t	key_length;
	size_t	value_length;

	key_value_pair = malloc(2 * sizeof(char *));
	if (key_value_pair == NULL)
		return (NULL);
	first_equal_sign = ft_strchr(env_var_line, '=');
	key_length = first_equal_sign - env_var_line;
	value_length = ft_strlen(first_equal_sign + 1);
	key_value_pair[0] = ft_substr(env_var_line, 0, key_length);
	key_value_pair[1] = ft_substr(env_var_line, key_length + 1, value_length);
	if (key_value_pair[0] == NULL || key_value_pair[1] == NULL)
	{
		if (key_value_pair[0])
			free(key_value_pair[0]);
		if (key_value_pair[1])
			free(key_value_pair[1]);
		free(key_value_pair);
		return (NULL);
	}
	return (key_value_pair);
}

t_list	*create_env_var_list(char **envp)
{
	t_list		*list;
	char		**key_value_pair;
	t_list		*added_node;

	list = NULL;
	while (*envp)
	{
		key_value_pair = split_env_var_line(*envp);
		if (key_value_pair == NULL)
		{
			free_env_var_list(&list);
			return (NULL);
		}
		added_node = set_env_var(key_value_pair[0], key_value_pair[1], &list);
		ft_free_str_arr(key_value_pair, 2);
		if (added_node == NULL)
		{
			free_env_var_list(&list);
			return (NULL);
		}
		envp++;
	}
	return (list);
}
