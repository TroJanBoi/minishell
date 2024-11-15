/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:08:05 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/11/15 21:24:04 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int check_path(char *cmd)
{
	if(access(cmd, X_OK) == SUCCESS)
	{
		// printf("%sSuccess access%s\n", GREEN, RESET);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}