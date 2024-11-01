/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:26:49 by nteechar          #+#    #+#             */
/*   Updated: 2024/10/25 16:25:54 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_LINE_H
# define PARSE_LINE_H

# include <stdlib.h>

# include "../libft/libft.h"
# include "../includes/constants.h"

# include "token/token.h"
# include "command/command.h"

t_list	*parse_line(char *line, int *parse_status);

#endif
