/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:32:16 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/20 17:59:27 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "../parse_line/create_commands/command.h"
# include "../setup/setup.h"

extern int		g_signal_global;

// < connect to execute >
int				is_builtin_name(char *name);
t_exit_status	execute_builtin(t_command *command, t_shell_data *data);

// putting
t_exit_status	builtin_echo(int argc, char **argv, t_shell_data *data);

// directories
t_exit_status	builtin_cd(int argc, char **argv, t_shell_data *data);
t_exit_status	builtin_pwd(int argc, char **argv, t_shell_data *data);

// environment variables
t_exit_status	builtin_env(int argc, char **argv, t_shell_data *data);
t_exit_status	builtin_export(int argc, char **argv, t_shell_data *data);
t_exit_status	builtin_unset(int argc, char **argv, t_shell_data *data);

// exit and free everything
void			builtin_exit(t_command *command, t_shell_data *data);
void			builtin_exit_0(t_shell_data *data);
void			builtin_exit_2(t_list **cmd_lst, t_shell_data *data);

#endif
