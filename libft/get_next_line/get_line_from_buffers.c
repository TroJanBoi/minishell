/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line_from_buffers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:08:28 by nteechar          #+#    #+#             */
/*   Updated: 2024/09/20 15:50:34 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	handle_buffer_with_newline(char **line, t_list **buffers,
	char *buffer)
{
	t_list	*next_node;

	ft_strlcat(*line, buffer,
		ft_strlen(*line) + (ft_strchr(buffer, '\n') - buffer + 1) + 1);
	ft_strlcpy(buffer, ft_strchr(buffer, '\n') + 1,
		ft_strlen(ft_strchr(buffer, '\n') + 1) + 1);
	if (ft_strlen(buffer) == 0)
	{
		next_node = (*buffers)->next;
		ft_lstdelone(*buffers, free);
		*buffers = next_node;
	}
}

static void	handle_buffer_no_newline(char **line, t_list **buffers,
	char *buffer)
{
	t_list	*next_node;

	ft_strlcat(*line, buffer, ft_strlen(*line) + ft_strlen(buffer) + 1);
	next_node = (*buffers)->next;
	ft_lstdelone(*buffers, free);
	*buffers = next_node;
}

int	get_line_from_buffers(char **line, t_list **buffers)
{
	char	*buffer;

	while (*buffers)
	{
		buffer = (*buffers)->content;
		if (ft_strchr(buffer, '\n'))
		{
			handle_buffer_with_newline(line, buffers, buffer);
			return (SUCCESS);
		}
		else
			handle_buffer_no_newline(line, buffers, buffer);
	}
	*buffers = NULL;
	return (SUCCESS);
}
