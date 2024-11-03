/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:16:44 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/11/03 17:18:55 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include <fcntl.h>
# include "../includes/minishell.h"
# include "../includes/constants.h"
# include "../__debugging/__debugging.h"

# include "t_exe.h"

extern int g_exit_status;
void	execute(t_list *command, char **envp);

t_exe	*init_cmd_list(t_list *commands);
void	free_exe_list(t_exe *cmd_list);
int		check_file(t_list *token);
void	ft_err(char *txt);
void	wait_allprocess(t_exe *cmd_lst);
#endif
