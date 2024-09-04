/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:50:49 by nteechar          #+#    #+#             */
/*   Updated: 2024/09/02 19:36:49 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*parse_line(char *line);
void	execute(t_list *pipeline);

void	manage_history(char *line)
{
	if (line && ft_strlen(line) > 0)
	{
		add_history(line);
	}
}


int	main(int argc, char **argv, char **envp)
{
	char	*line;
	t_list	*pipeline;

	setup_signal();
	while (1)
	{
		line = readline("minishell> ");
		if (!line)
			break ;
		manage_history(line);
		pipeline = parse_line(line);
		if (pipeline == NULL)
			return (EXIT_FAILURE);
		execute(pipeline);
	}
}
