/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:32:16 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/27 15:06:56 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "../parser/create_commands/command.h"
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

// free everything and exit
void			builtin_exit(int argc, char **argv, t_shell_data *data);

#endif
