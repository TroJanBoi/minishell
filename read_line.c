/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:42:36 by nteechar          #+#    #+#             */
/*   Updated: 2024/12/05 14:37:12 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "readline/readline.h"
#include "readline/history.h"
#include "libft/libft.h"
#include "setup/shell_data.h"

#define AS_BIG_AS_NECESSARY 0

// minishell with red 's' and red+underline 'hell'
#define MINISHELL "\2mini\1\033[31m\2s\1\033[0m\033[4;31m\2hell\1\033[0m\2"

static char	*get_prompt(void)
{
	char	*path;
	char	*prompt;

	path = getcwd(NULL, AS_BIG_AS_NECESSARY);
	if (path == NULL)
		return (NULL);
	prompt = ft_strjoin_all(4, MINISHELL, ":", path, "$ ");
	free(path);
	if (prompt == NULL)
		return (NULL);
	return (prompt);
}

static char	*get_line(t_shell_data *data)
{
	char	*prompt;
	char	*line;

	prompt = get_prompt();
	if (prompt == NULL)
	{
		data->exit_status = ENOMEM;
		return (NULL);
	}
	// line = readline(prompt);
	line = get_next_line(STDIN_FILENO);
	free(prompt);
	if (line == NULL)
		return (NULL);
	line[ft_strlen(line) - 1] = '\0';
	return (line);
}

char	*read_line(t_shell_data *data)
{
	char	*line;

	line = get_line(data);
	if (line == NULL)
		return (NULL);
	if (ft_strlen(line) > 0)
		add_history(line);
	return (line);
}
