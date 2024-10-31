/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_allprocess.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 22:04:34 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/10/16 22:20:16 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	wait_allprocess(t_exe *cmd_lst)
{
	while (cmd_lst)
	{
		waitpid(cmd_lst->pid, NULL, 0);
		cmd_lst = cmd_lst->next;
	}
}