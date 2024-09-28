/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:13:53 by nteechar          #+#    #+#             */
/*   Updated: 2024/09/20 14:59:41 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include "../../libft/libft.h"

// command _class
typedef struct s_commands
{
	char	**argv;
	t_list	*redirs;
}	t_command;

void	free_command(void *command);

#endif
