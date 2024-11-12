/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __debugging.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:36:18 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/12 13:17:48 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DEBUGGING_H
# define __DEBUGGING_H

# include <sys/types.h>
# include <sys/wait.h>
# include "../libft/libft.h"
# include "../execute/execute.h"
# include "colors.h"

void	print_tokens(t_list *tokens, char *var_name);

void	print_commands(t_list *commands);

void	print_string_arr(char **arr, char *var_name);
void	print_string_list(t_list *strings, char *var_name);

void	print_execute_commands(t_list *exe_list);

#endif
