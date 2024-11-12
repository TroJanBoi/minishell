/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:34:10 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/12 11:36:03 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "builtin.h"

// print all environment variables
int	builtin_env(int argc, char **argv, t_shell_data *data)
{
	(void) argc;
	(void) argv;
	print_env_var_list(data->env_var_list);
	return (SUCCESS);
}
