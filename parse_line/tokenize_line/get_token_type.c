/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:47:21 by nteechar          #+#    #+#             */
/*   Updated: 2024/10/16 16:48:29 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse_line.h"

t_token_type	get_token_type(char *line)
{
	if (ft_strncmp(line, ">>", 2) == 0)
		return (APPEND);
	if (ft_strncmp(line, ">", 1) == 0)
		return (OUTFILE);
	if (ft_strncmp(line, "<<", 2) == 0)
		return (HEREDOC);
	if (ft_strncmp(line, "<", 1) == 0)
		return (INFILE);
	if (ft_strncmp(line, "|", 1) == 0)
		return (PIPE);
	return (WORD);
}