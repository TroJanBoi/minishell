/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:42:36 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/27 17:11:27 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <errno.h>
#include "readline/readline.h"
#include "readline/history.h"
#include "libft/libft.h"
#include "setup/setup.h"

#define AS_BIG_AS_NECESSARY 0

#define S_RED "\033[31m"
#define HELL_RED "\033[4;31m"
#define RESET "\033[0m"
#define MINISHELL "minis\1"RESET HELL_RED"\2hell\1"RESET"\2"

static char	*get_prompt(void)
{
	char	*path;
	char	*prompt;

	path = getcwd(NULL, AS_BIG_AS_NECESSARY);
	if (path == NULL)
		return (NULL);
	prompt = ft_strjoin_all(4, MINISHELL, ":", path, "$ ");
	free(path);
	return (prompt);
}

char	*read_line(t_shell_data *data)
{
	char	*prompt;
	char	*line;

	prompt = get_prompt();
	if (prompt == NULL)
	{
		data->exit_status = ENOMEM;
		return (NULL);
	}
	line = readline(prompt);
	free(prompt);
	if (line == NULL)
		return (NULL);
	if (ft_strlen(line) > 0)
		add_history(line);
	return (line);
}
