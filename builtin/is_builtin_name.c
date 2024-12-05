/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:40:18 by nteechar          #+#    #+#             */
/*   Updated: 2024/12/02 18:05:17 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h>

int	is_builtin_name(char *name)
{
	if (!name)
		return (0);
	return (ft_strcmp(name, "cd") == 0 || ft_strcmp(name, "echo") == 0
		|| ft_strcmp(name, "env") == 0 || ft_strcmp(name, "exit") == 0
		|| ft_strcmp(name, "export") == 0 || ft_strcmp(name, "pwd") == 0
		|| ft_strcmp(name, "unset") == 0);
}

// check for "parent"-type builtin
int	is_p_builtin_name(char *name)
{
	if (!name)
		return (0);
	return (ft_strcmp(name, "cd") == 0 || ft_strcmp(name, "exit") == 0
		|| ft_strcmp(name, "export") == 0 || ft_strcmp(name, "unset") == 0);
}
