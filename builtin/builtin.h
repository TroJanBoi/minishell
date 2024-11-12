/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:32:16 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/12 12:01:09 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "../setup/setup.h"

// putting
int		builtin_echo(int argc, char **argv);

// directories
int		builtin_cd(int argc, char **argv, t_shell_data *data);
int		builtin_pwd(int argc, char **argv);

// environment variables
int		builtin_env(int argc, char **argv, t_shell_data *data);
int		builtin_export(int argc, char **argv, t_shell_data *data);
int		builtin_unset(int argc, char **argv, t_shell_data *data);

// exit and free everything
void	builtin_exit(t_list *command_list, t_shell_data *data);

#endif
