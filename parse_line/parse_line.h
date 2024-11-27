/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:39:48 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/15 12:14:44 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_LINE_H
# define PARSE_LINE_H

# include "../setup/setup.h"

# include "tokenize/token.h"
# include "create_commands/command.h"

t_list	*parse_line(char *line, t_shell_data *data);

#endif
