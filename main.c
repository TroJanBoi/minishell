/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:50:49 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/27 17:11:19 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <errno.h>
#include "libft/libft.h"
#include "builtin/builtin.h"
#include "parse_line/parse_line.h"
#include "execute/execute.h"

int		g_signal_global = 0;
char	*read_line(t_shell_data *data);

int	is_quote_closed(char *line)
{
	int	state;

	state = OUTSIDE;
	while (*line)
	{
		if (state == OUTSIDE)
		{
			if (*line == '\'')
				state = INSIDE_SINGLE_QUOTE;
			else if (*line == '\"')
				state = INSIDE_DOUBLE_QUOTE;
		}
		else if (state == INSIDE_SINGLE_QUOTE)
		{
			if (*line == '\'')
				state = OUTSIDE;
		}
		else if (state == INSIDE_DOUBLE_QUOTE)
		{
			if (*line == '\"')
				state = OUTSIDE;
		}
		line++;
	}
	return (state == OUTSIDE);
}

// error handling is done by three sub-functions
int	main(int argc, char **argv, char **envp)
{
	t_shell_data	*data;
	char			*line;
	t_list			*command_list;

	data = init(argc, argv, envp);
	if (data == NULL)
		return (EXIT_FAILURE);
	while (TRUE)
	{
		g_signal_global = 0;
		line = read_line(data);
		if (data->exit_status == ENOMEM)
			builtin_exit_0(data);
		else if (line == NULL)
			builtin_exit_0(data);
		else if (ft_strlen(line) == 0)
		{
			free(line);
			continue ;
		}
		else if (!is_quote_closed(line))
		{
			ft_putstr_fd("minishell: unclosed quote found\n", STDERR_FILENO);
			free(line);
			continue ;
		}
		command_list = parse_line(line, data);
		free(line);
		if (data->exit_status == EINVAL)
		{
			ft_putstr_fd("minishell: syntax error\n", STDERR_FILENO);
			continue ;
		}
		else if (data->exit_status != SUCCESS)
			builtin_exit_0(data);
		g_signal_global = 1;
		data->exit_status = main_execute(command_list, data);
	}
}
