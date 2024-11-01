/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __debugging.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:36:18 by nteechar          #+#    #+#             */
/*   Updated: 2024/10/29 17:54:11 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DEBUGGING_H
# define __DEBUGGING_H

# include "../libft/libft.h"
# include "../execute/t_exe.h"

void	print_tokens(t_list *tokens, char *var_name);

void	print_commands(t_list *commands);

void	print_string_arr(char **arr, char *var_name);
void	print_string_list(t_list *strings, char *var_name);

void	print_commands_exe(t_exe *exe_list);

#endif
