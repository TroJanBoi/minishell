/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:43:04 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/27 15:30:54 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "setup.h"

void	setup_signal(void);

t_shell_data	*init_minishell(int argc, char **argv, char **envp)
{
	t_shell_data	*data;

	disable_sigquit_echo();
	setup_signal();
	data = create_shell_data(argc, argv, envp);
	if (data == NULL)
		return (NULL);
	return (data);
}
