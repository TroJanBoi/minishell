/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:39:58 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/20 17:48:28 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/libft.h"
#include "env_var.h"

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
// - if key is already in the list, replace value
t_list	*set_env_var(char *key, char *value, t_list **env_var_list)
{
	t_list		*node;
	t_env_var	*var;
	char		*temp;

	node = find_env_var(key, *env_var_list);
	if (node)
	{
		var = node->content;
		temp = ft_strdup(value);
		if (temp == NULL)
			return (NULL);
		free(var->value);
		var->value = temp;
		return (node);
	}
	var = create_env_var(key, value);
	if (var == NULL)
		return (NULL);
	node = ft_lstnew_add_back(env_var_list, var);
	if (node == NULL)
	{
		free_env_var(var);
		return (NULL);
	}
	return (node);
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

char	**get_envp(t_list *env_var_list)
{
	char		**arr;
	t_env_var	*env_var;
	size_t		i;

	arr = malloc((ft_lstsize(env_var_list) + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (env_var_list)
	{
		env_var = env_var_list->content;
		arr[i] = ft_strjoin_all(3, env_var->key, "=", env_var->value);
		if (arr[i] == NULL)
		{
			ft_free_str_arr(arr, i);
			return (NULL);
		}
		i++;
		env_var_list = env_var_list->next;
	}
	arr[i] = NULL;
	return (arr);
}
