/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:26:49 by nteechar          #+#    #+#             */
/*   Updated: 2024/09/20 16:41:51 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_LINE_H
# define PARSE_LINE_H

# include "../libft/libft.h"
# include "../constants.h"

# include "token/token.h"
# include "command/command.h"

# include "../__debugging.h"

t_list	*parse_line(char *line, int *parse_status);

#endif
