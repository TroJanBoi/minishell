/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:13:53 by nteechar          #+#    #+#             */
/*   Updated: 2024/10/25 16:10:24 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

// command class
typedef struct s_commands
{
	int		argc;
	char	**argv;
	t_list	*redirs;
}	t_command;

void	free_command(void *command);

#endif
