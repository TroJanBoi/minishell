/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:39:58 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/11 18:53:21 by nteechar         ###   ########.fr       */
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
		added_node = add_env_var(key_value_pair[0], key_value_pair[1], &list);
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

void	free_env_var_list(t_list **env_var_list)
{
	ft_lstclear(env_var_list, free_env_var);
}

// return ptr to the env_var's node having "key"
t_list	*find_env_var(char *key, t_list *env_var_list)
{
	t_env_var	*var;

	while (env_var_list)
	{
		var = env_var_list->content;
		if (ft_strcmp(var->key, key) == 0)
			return (env_var_list);
		env_var_list = env_var_list->next;
	}
	return (NULL);
}

// return address of env_var's node if malloc'd successfully, NULL if not
t_list	*add_env_var(char *key, char *value, t_list **env_var_list)
{
	t_list		*added_node;
	t_env_var	*var;

	var = create_env_var(key, value);
	if (var == NULL)
		return (NULL);
	added_node = ft_lstnew_add_back(env_var_list, var);
	if (added_node == NULL)
	{
		free_env_var(var);
		return (NULL);
	}
	return (added_node);
}

void	del_env_var(char *key, t_list **env_var_list)
{
	t_list	*matched_node;

	matched_node = find_env_var(key, *env_var_list);
	if (matched_node == NULL)
		return ;
	ft_lstdelone(matched_node, free_env_var);
}

void	print_env_var_list(t_list *env_var_list)
{
	t_env_var	*var;

	while (env_var_list)
	{
		var = env_var_list->content;
		printf("%s=%s\n", var->key, var->value);
		env_var_list = env_var_list->next;
	}
}
