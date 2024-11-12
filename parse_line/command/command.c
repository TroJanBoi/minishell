/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:39:51 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/12 15:09:55 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../token/token.h"
#include "command.h"

// t_command	*create_command(char **argv, t_token *redirs)
// {
// 	t_command	*command;

// 	(void) argv; (void) redirs;
// 	command = NULL;
// 	return (command);
// }

void	free_command(void *command)
{
	t_command	*command_;
	int			i;

	command_ = command;
	i = 0;
	while (command_->argv[i])
	{
		free(command_->argv[i]);
		i++;
	}
	free(command_->argv);
	ft_lstclear(&command_->redirs, free_token);
	free(command_);
}
