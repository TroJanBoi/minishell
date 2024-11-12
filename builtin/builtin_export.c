/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:33:51 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/11 19:06:20 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "builtin.h"

static void	export_single_var(char *env_var_line, t_shell_data *data)
{
	char	**key_value_pair;
	char	*key;
	char	*value;
	t_list	*added_node;

	key_value_pair = split_env_var_line(env_var_line);
	if (key_value_pair == NULL)
	{
		// cleanup
		return ;
	}
	key = key_value_pair[0];
	value = key_value_pair[1];
	if (!ft_isalpha(key[0]))
	{
		ft_putstr_fd("minishell: export: '", STDERR_FILENO);
		ft_putstr_fd(key, STDERR_FILENO);
		ft_putstr_fd("': not a valid identifier", STDERR_FILENO);
		return ;
	}
	added_node = add_env_var(key, value, &data->env_var_list);
	ft_free_str_arr(key_value_pair, 2);
	if (added_node == NULL)
	{
		// cleanup
		return ;
	}
}

// - set environment variable(s)
// - usage: export key[=value] ...
// - iterate over each argv
// - key must begin with alphabet, if not,
//   log error, set errno and don't set env var
// - if value is not given, don't set env var
int	builtin_export(int argc, char **argv, t_shell_data *data)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		export_single_var(argv[i], data);
		i++;
	}
	return (SUCCESS);
}
