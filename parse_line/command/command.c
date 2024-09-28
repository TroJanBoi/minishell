/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:39:51 by nteechar          #+#    #+#             */
/*   Updated: 2024/09/20 13:49:16 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse_line.h"

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
