/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:50:49 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/27 15:48:29 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "libft/libft.h"
#include "setup/setup.h"
#include "parser/parse_line.h"
#include "builtin/builtin.h"
#include "execute/execute.h"

int		g_signal_global = READ_MODE;

char	*read_line(t_shell_data *data);

static void	evaluate_line(char *line, t_shell_data *data)
{
	t_command_list	*commands;

	commands = parse_line(line, data);
	if (data->exit_status == EINVAL || commands == NULL)
		return ;
	else if (data->exit_status == ENOMEM)
		builtin_exit(0, NULL, data);
	data->exit_status = main_execute(commands, data);
}

static void	main_loop(t_shell_data *data)
{
	char	*line;

	while (TRUE)
	{
		g_signal_global = READ_MODE;
		line = read_line(data);
		if (line == NULL)
		{
			if (errno == ENOMEM)
				data->exit_status = ENOMEM;
			builtin_exit(0, NULL, data);
		}
		g_signal_global = EXECUTE_MODE;
		evaluate_line(line, data);
		free(line);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_shell_data	*data;

	if (argc > 2)
	{
		ft_putstr_fd("Usage: ./minishell [line]\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	data = init_minishell(argc, argv, envp);
	if (data == NULL)
		return (EXIT_FAILURE);
	if (argc == 2)
	{
		evaluate_line(argv[1], data);
		builtin_exit(0, NULL, data);
	}
	main_loop(data);
}
