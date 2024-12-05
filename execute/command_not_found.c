/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_not_found.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:20:02 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/11/27 13:45:31 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	command_not_found(char *cmd, int fd)
{
	ft_putstr_fd(cmd, fd);
	ft_putendl_fd(": command not found", fd);
	// free everything
	exit(ISSUE_PATH);
}
