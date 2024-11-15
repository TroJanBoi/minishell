/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_backslash.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:13:31 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/11/14 17:17:56 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	check_backslash(char *cmd)
{
	int count;

	count = 0;
	if (!cmd)
		return (EXIT_FAILURE);
	while(*cmd)
	{
		if(*cmd == '/')
			count++;
		cmd++;
	}
	if (count > 0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}