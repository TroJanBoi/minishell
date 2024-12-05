/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:18:48 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/26 09:39:11 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "builtin.h"

static char	*get_path(int argc, char **argv, t_list *env_var_list)
{
	t_list		*node;
	t_env_var	*env_var;
	char		*path;

	if (argc == 1)
	{
		node = find_env_var("HOME", env_var_list);
		if (node == NULL)
		{
			ft_putstr_fd("minishell: cd: HOME not set\n", STDERR_FILENO);
			return (NULL);
		}
		env_var = node->content;
		path = env_var->value;
	}
	else
		path = argv[1];
	return (path);
}

static void	put_error_message(char *path)
{
	ft_putstr_fd("minishell: cd: ", STDERR_FILENO);
	ft_putstr_fd(path, STDERR_FILENO);
	ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
}

t_exit_status	builtin_cd(int argc, char **argv, t_shell_data *data)
{
	char			*path;
	t_exit_status	ret;

	if (argc >= 3)
	{
		ft_putstr_fd("minishell: cd: too many arguments\n", STDERR_FILENO);
		return (ERROR);
	}
	path = get_path(argc, argv, data->env_var_list);
	if (path == NULL)
		return (ERROR);
	ret = chdir(path);
	if (ret != SUCCESS)
		put_error_message(path);
	return (ret);
}
