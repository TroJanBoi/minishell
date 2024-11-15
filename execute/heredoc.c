/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 22:35:24 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/11/15 02:21:06 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	ft_heredoc(char *delimiter)
{
	int		pipe_fd[2];
	char	*line;

	if (pipe(pipe_fd) == -1)
	{
		perror("pipe failed");
		return (-1);
	}
	while (1)
	{
		write(1, "heredoc> ", 9);
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break;
		if (ft_strncmp(line, delimiter, ft_strlen(delimiter)) == SUCCESS)
		{
			free(line);
			break;
		}
		write(pipe_fd[1], line, ft_strlen(line));
		free(line);
	}
	close(pipe_fd[1]);
	return (pipe_fd[0]);
}
