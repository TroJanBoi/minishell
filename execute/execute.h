/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:16:44 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/10/04 14:58:26 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "../minishell.h"
# include "../colors.h"
# include "../constants.h"
# include "../__debugging.h"

typedef struct s_exe
{
	t_command          *command;
	int				fd[2];
	int				fd_in;
	int				fd_out;
	struct s_exe	*next;
}	t_exe;

void	execute(t_list *command, char **envp);
void	free_exe_list(t_exe *cmd_list);
int		check_file(t_list *token);

#endif