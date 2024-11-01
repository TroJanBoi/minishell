/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:32:16 by nteechar          #+#    #+#             */
/*   Updated: 2024/10/25 18:02:08 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "../includes/t_shell_data.h"
# include "../parse_line/parse_line.h"
# include "../env_var/env_var.h"

void	builtin_echo(t_command *command, t_shell_data *data);
void	builtin_cd(t_command *command, t_shell_data *data);
void	builtin_pwd(t_command *command, t_shell_data *data);
void	builtin_env(t_command *command, t_shell_data *data);
void	builtin_export(t_command *command, t_shell_data *data);
void	builtin_unset(t_command *command, t_shell_data *data);

void	builtin_exit(t_list *commands, t_shell_data *data);

#endif
