/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:43:30 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/11/14 17:59:56 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

char	*join_path(char **full_path, char *cmd)
{
	char	*path;
	char	*tmp;

	path = ft_substr("", 0, 0);
	while (*full_path)
	{
		tmp = path;
		path = ft_strjoin(*full_path, "/");
		free(tmp);
		tmp = path;
		path = ft_strjoin(path, cmd);
		free(tmp);
		if (check_path(path) == SUCCESS)
			return (path);
		full_path++;
	}
	return (NULL);
}