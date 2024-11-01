/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:16:44 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/10/29 18:23:39 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include <fcntl.h>
# include "../includes/minishell.h"
# include "../includes/constants.h"
# include "../__debugging/__debugging.h"

# include "t_exe.h"

void	execute(t_list *command, char **envp);

t_exe	*init_cmd_list(t_list *commands);
void	free_exe_list(t_exe *cmd_list);
int		check_file(t_list *token);
void	ft_err(char *txt);

#endif
