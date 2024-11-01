/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:42:36 by nteechar          #+#    #+#             */
/*   Updated: 2024/10/29 18:21:53 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_prompt(void)
{
	char	*cwd;
	char	*prompt;

	cwd = getcwd(NULL, 0);
	if (cwd == NULL)
		return (NULL);
	prompt = ft_strjoin_all(3, "minishell:", cwd, "$ ");
	free(cwd);
	if (prompt == NULL)
		return (NULL);
	return (prompt);
}

// WARNING
// get_next_line to be replaced with readline later
// feof is forbidden!!!!
char	*ft_readline(t_shell_data *data)
{
	char	*prompt;	
	char	*line;

	prompt = get_prompt();
	if (prompt == NULL)
		return (NULL);
	line = readline(prompt);
	free(prompt);
	if (line == NULL)
	{
		if (feof(stdin))
			data->is_running = FALSE;
		return (NULL);
	}
	if (ft_strlen(line) > 0)
		add_history(line);
	return (line);
}
