/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluate_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:43:53 by nteechar          #+#    #+#             */
/*   Updated: 2024/10/29 18:26:54 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "../libft/libft.h"
#include "../parse_line/parse_line.h"
#include "../execute/execute.h"
#include "../includes/t_shell_data.h"

t_list	*parse_line(char *line, int *parse_status);

static int	execute_builtin_if_able(t_list *commands, t_shell_data *data)
{
	t_command	*first_command;

	first_command = commands->content;
	if (ft_strcmp(first_command->argv[0], "echo") == 0)
		builtin_echo(first_command, data);
	else if (ft_strcmp(first_command->argv[0], "cd") == 0)
		builtin_cd(first_command, data);
	else if (ft_strcmp(first_command->argv[0], "pwd") == 0)
		builtin_pwd(first_command, data);
	else if (ft_strcmp(first_command->argv[0], "env") == 0)
		builtin_env(first_command, data);
	else if (ft_strcmp(first_command->argv[0], "export") == 0)
		builtin_export(first_command, data);
	else if (ft_strcmp(first_command->argv[0], "unset") == 0)
		builtin_unset(first_command, data);
	else if (ft_strcmp(first_command->argv[0], "exit") == 0)
		builtin_exit(commands, data);
	else
		return (FALSE);
	return (TRUE);
}

static void	ft_execute(t_list *commands, t_shell_data *data)
{
	if (ft_lstsize(commands) == 1 && execute_builtin_if_able(commands, data))
		return ;
	execute(commands, data->envp);
}

void	evaluate_line(char *line, t_shell_data *data)
{
	t_list	*commands;
	int		parse_status;

	if (ft_strlen(line) == 0)
	{
		free(line);
		return ;
	}
	commands = parse_line(line, &parse_status);
	free(line);
	if (parse_status == ENOMEM || parse_status == EINVAL)
	{
		data->exit_status = parse_status;
		return ;
	}
	ft_execute(commands, data);
}
