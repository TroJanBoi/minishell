/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 20:42:01 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/09/06 18:22:49 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "../minishell.h"
# include <fcntl.h>

typedef struct s_exe
{
	pid_t	pid;
	int		fd[2];
	int		fdtemp;
}	t_exe;

#endif

