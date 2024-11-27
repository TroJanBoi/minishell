/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:18:48 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/16 16:53:20 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "builtin.h"

static char	*get_path(int argc, char **argv, t_list *env_var_list)
{
	t_list	*node;
	char	*path;

	if (argc == 1)
	{
		node = find_env_var("HOME", env_var_list);
		if (node == NULL)
		{
			ft_putstr_fd("minishell: cd: HOME not set\n", STDERR_FILENO);
			return (NULL);
		}
		path = ((t_env_var *) node->content)->value;
	}
	else
		path = argv[1];
	return (path);
}

t_exit_status	builtin_cd(int argc, char **argv, t_shell_data *data)
{
	t_exit_status	ret;
	char			*path;

	if (argc >= 3)
	{
		ft_putendl_fd("minishell: cd: too many arguments", STDERR_FILENO);
		return (ERROR);
	}
	path = get_path(argc, argv, data->env_var_list);
	if (path == NULL)
		return (ERROR);
	ret = chdir(path);
	if (ret != SUCCESS)
	{
		ft_putstr_fd("minishell: cd: ", STDERR_FILENO);
		ft_putstr_fd(path, STDERR_FILENO);
		ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
	}
	return (ret);
}
