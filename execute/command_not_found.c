/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_not_found.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:20:02 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/11/20 01:25:10 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	command_not_found(char *cmd, int fd)
{
	ft_putstr_fd(cmd, fd);
	ft_putendl_fd(": command not found", fd);
	exit(ISSUE_PATH);
}
