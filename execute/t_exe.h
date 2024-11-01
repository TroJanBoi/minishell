/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_exe.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:51:54 by nteechar          #+#    #+#             */
/*   Updated: 2024/10/29 17:53:53 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_EXE_H
# define T_EXE_H

# include "../parse_line/command/command.h"

typedef struct s_exe
{
	t_command		*command;
	int				fd[2];
	int				fd_prev;
	int				fd_in;
	int				fd_out;
	struct s_exe	*next;
	pid_t			pid;
}	t_exe;

#endif
