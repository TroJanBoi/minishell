/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:50:49 by nteechar          #+#    #+#             */
/*   Updated: 2024/10/29 17:51:32 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include "../includes/t_shell_data.h"

int		init(t_shell_data *data, char **envp);
char	*ft_readline(t_shell_data *data);
void	evaluate_line(char *line, t_shell_data *data);

int	main(int argc, char **argv, char **envp)
{
	t_shell_data	data;
	char			*line;

	if (init(&data, envp) != SUCCESS)
		return (EXIT_FAILURE);
	while (data.is_running)
	{
		line = ft_readline(&data);
		if (line == NULL)
			break ;
		evaluate_line(line, &data);
		if (data.exit_status == ENOMEM)
			break ;
	}
	return (data.exit_status);
}
