/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:57:55 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/11 17:00:45 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETUP_H
# define SETUP_H

# include "../libft/list/t_list.h"
# include "constants.h"
# include "env_var.h"

typedef int t_exit_status;

typedef struct s_shell_data
{
	t_exit_status	exit_status;
	t_list			*env_var_list;
}	t_shell_data;

t_shell_data	*create_shell_data(int argc, char **argv, char **envp);
void			free_shell_data(t_shell_data *data);

t_shell_data	*init(int argc, char **argv, char **envp);

#endif
