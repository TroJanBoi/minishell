/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:23:20 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/11/20 01:27:10 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

char	*find_path(char *key, t_list *env_var_lst, char *cmd)
{
	t_list		*path_node;
	t_env_var	*env_var;
	char		*path;
	char		**full_path;

	if (!key || !env_var_lst)
		return (NULL);
	path_node = find_env_var(key, env_var_lst);
	env_var = (t_env_var *)path_node->content;
	full_path = ft_split(env_var->value, ':');
	path = join_path(full_path, cmd);
	if (path != NULL)
	{
		ft_free_str_arr(full_path, 0);
		return (path);
	}
	ft_free_str_arr(full_path, 0);
	return (NULL);
}
