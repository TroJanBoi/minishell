/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:50:49 by nteechar          #+#    #+#             */
/*   Updated: 2024/10/02 21:36:10 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	manage_history(char *line);
// void	execute(t_list *pipeline);

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	t_list	*commands;
	int		parse_status;

	// setup_signal();
	while (1)
	{
		// line = readline("minishell> ");
		
		// using get_next_line to track leaks
		write(1, "minishell> ", 11); line = get_next_line(STDIN_FILENO); line[ft_strlen(line) - 1] = '\0';

		// manage_history(line);
		if (ft_strncmp(line, "exit", 4) == 0)
		{
			free(line);
			break ;
		}
		if (ft_strlen(line) == 0)
		{
			free(line);
			continue ;
		}
		commands = parse_line(line, &parse_status);
		free(line);
		if (parse_status == ENOMEM)
			return (EXIT_FAILURE);
		else if (parse_status == EINVAL)
		{
			printf("minishell: syntax error\n");
			continue ;
		}
		// print_commands(commands);
		execute(commands, envp);
		// ft_lstclear(&commands, free_command);
	}
	return (EXIT_SUCCESS);
}
