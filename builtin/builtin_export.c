/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:33:51 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/27 14:41:37 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "builtin.h"
#include "../libft/libft.h"
#include "../env_var/env_var.h"

#define NOT_A_VALID_KEY 1

static int	export_single_var(char *env_var_line, t_shell_data *data)
{
	char		**key_value_pair;
	char		*key;
	char		*value;
	t_list		*node;

	if (ft_strchr(env_var_line, '='))
	{
		key_value_pair = split_env_var_line(env_var_line);
		if (key_value_pair == NULL)
			return (ENOMEM);
		key = key_value_pair[0];
		value = key_value_pair[1];
		if (!is_valid_key(key))
			return (NOT_A_VALID_KEY);
		node = set_env_var(key, value, &data->env_var_list);
		ft_free_str_arr(key_value_pair, 2);
		if (node == NULL)
			return (ENOMEM);
	}
	else
	{
		if (!is_valid_key(env_var_line))
			return (NOT_A_VALID_KEY);
	}
	return (SUCCESS);
}

// - set environment variable(s)
//
// - usage: export key[=value] ...
//
// - iterate over each argv
// - valid key: [A-Za-z][A-Za-z0-9_]+
// - if value is not given, don't set env var
t_exit_status	builtin_export(int argc, char **argv, t_shell_data *data)
{
	t_exit_status	ret;
	int				export_status;
	int				i;

	ret = SUCCESS;
	i = 1;
	while (i < argc)
	{
		export_status = export_single_var(argv[i], data);
		if (export_status == ENOMEM)
		{
			ret = ENOMEM;
			break ;
		}
		else if (export_status == NOT_A_VALID_KEY)
		{
			ret = ERROR;
			ft_putstr_fd("minishell: export: '", STDERR_FILENO);
			ft_putstr_fd(argv[i], STDERR_FILENO);
			ft_putstr_fd("': not a valid identifier\n", STDERR_FILENO);
		}
		i++;
	}
	return (ret);
}
