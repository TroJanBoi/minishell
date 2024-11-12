/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:16:44 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/11/12 15:20:10 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include <fcntl.h>
# include "../setup/setup.h"
# include "../parse_line/parse_line.h"

#  include "../__debugging/__debugging.h"
#  include <stdio.h>

typedef struct s_execute_command
{
	t_command	*command;
	int			pipe_fds[2];
	int			fd_prev;
	int			fd_in;
	int			fd_out;
	pid_t		pid;
}	t_execute_command;

t_exit_status	execute(t_list *command, char **envp);

t_list	*init_execute_command_list(t_list *commands);
void	free_execute_command_list(t_list **execute_command_list);

int		check_file(t_list *token);

#endif
