/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:07:39 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/10/29 17:37:42 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	free_exe_list(t_exe *head)
{
	t_exe	*temp;

	while (head)
	{
		temp = head;
		head = head->next;
		if (temp->command)
			free_command(temp->command);
		free(temp);
	}
}
