/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:50:49 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/12 15:09:29 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "libft/libft.h"
#include "builtin/builtin.h"
#include "parse_line/parse_line.h"
#include "execute/execute.h"

char	*read_line(t_shell_data *data);

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
		line = read_line(data);
		if (line == NULL)
			builtin_exit(NULL, data);
		if (ft_strlen(line) == 0)
		{
			free(line);
			continue ;
		}
		command_list = parse_line(line, data);
		free(line);
		if (command_list == NULL)
			builtin_exit(NULL, data);
		data->exit_status = execute(command_list, envp);
		// printf("execute finish\n");
		// printf("free start\n");
		// ft_lstclear(&command_list, free_command);
		// printf("free finish\n");
	}
}
