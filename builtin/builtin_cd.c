/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:18:48 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/12 11:54:58 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "builtin.h"

static void	handle_many_inputs(void)
{
	ft_putendl_fd("minishell: cd: too many arguments", STDERR_FILENO);
	// data->exit_status = EXIT_FAILURE;
}

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
			// data->exit_status = EXIT_FAILURE;
			return (NULL);
		}
		path = ((t_env_var *) node->content)->value;
	}
	else
		path = argv[1];
	return (path);
}

static void	change_directory(char *path)
{
	if (chdir(path) < SUCCESS)
	{
		ft_putstr_fd("minishell: cd: ", STDERR_FILENO);
		ft_putstr_fd(path, STDERR_FILENO);
		ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
		// data->exit_status = EXIT_FAILURE;
	}
	else
	{
		// data->exit_status = EXIT_SUCCESS;
	}
}

int	builtin_cd(int argc, char **argv, t_shell_data *data)
{
	char	*path;

	if (argc >= 3)
	{
		handle_many_inputs();
		return (ERROR);
	}
	path = get_path(argc, argv, data->env_var_list);
	if (path == NULL)
		return (ERROR);
	change_directory(path);
	return (SUCCESS);
}
