/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:11:16 by nteechar          #+#    #+#             */
/*   Updated: 2024/10/25 15:01:27 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft.h"
#include "get_next_line.h"

static int	have_newline(t_list *buffers)
{
	char	*buffer;

	while (buffers)
	{
		buffer = buffers->content;
		if (ft_strchr(buffer, '\n'))
			return (TRUE);
		buffers = buffers->next;
	}
	return (FALSE);
}

static int	read_file(int fd, t_list **buffers)
{
	char	*buffer;
	ssize_t	chars_read;

	while (1)
	{
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (buffer == NULL)
			return (1);
		chars_read = read(fd, buffer, BUFFER_SIZE);
		if (chars_read == -1 || chars_read == 0)
		{
			free(buffer);
			return (chars_read);
		}
		buffer[chars_read] = '\0';
		if (ft_lstnew_add_back(buffers, buffer) == NULL)
		{
			free(buffer);
			return (ERROR);
		}
		if (ft_strchr(buffer, '\n'))
			return (SUCCESS);
	}
}

static int	malloc_line(char **line, t_list *buffers)
{
	size_t	length;
	char	*buffer;

	length = 0;
	while (buffers)
	{
		buffer = buffers->content;
		if (ft_strchr(buffer, '\n'))
		{
			length += ft_strchr(buffer, '\n') - buffer + 1;
			break ;
		}
		else
			length += ft_strlen(buffer);
		buffers = buffers->next;
	}
	*line = malloc((length + 1) * sizeof(char));
	if (*line == NULL)
		return (ERROR);
	*line[0] = '\0';
	return (SUCCESS);
}

int	get_line_from_buffers(char **line, t_list **buffers);

char	*get_next_line(int fd)
{
	static t_list	*buffers = NULL;
	char			*line;

	if (buffers == NULL || !have_newline(buffers))
	{
		if (read_file(fd, &buffers) != SUCCESS)
		{
			ft_lstclear(&buffers, free);
			return (NULL);
		}
		if (buffers == NULL)
			return (NULL);
	}
	if (malloc_line(&line, buffers) != SUCCESS)
	{
		ft_lstclear(&buffers, free);
		return (NULL);
	}
	if (get_line_from_buffers(&line, &buffers) != SUCCESS)
	{
		ft_lstclear(&buffers, free);
		return (NULL);
	}
	return (line);
}
