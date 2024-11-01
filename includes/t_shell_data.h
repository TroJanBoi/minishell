/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_shell_data.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:08:26 by nteechar          #+#    #+#             */
/*   Updated: 2024/10/29 18:01:49 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_SHELL_DATA_H
# define T_SHELL_DATA_H

# include "../libft/libft.h"

typedef struct s_shell_data
{
	int		is_running;
	int		exit_status;
	t_list	*env_vars;
	char	**envp;
}	t_shell_data;

#endif
