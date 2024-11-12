/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:42:36 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/12 12:02:17 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "readline/readline.h"
#include "readline/history.h"
#include "libft/libft.h"
#include "setup/setup.h"

// char	*get_prompt(void)
// {
// 	char	*cwd;
// 	char	*prompt;

// 	cwd = getcwd(NULL, 0);
// 	if (cwd == NULL)
// 		return (NULL);
// 	prompt = ft_strjoin_all(3, "minishell:", cwd, "$ ");
// 	free(cwd);
// 	if (prompt == NULL)
// 		return (NULL);
// 	return (prompt);
// }
char	*get_prompt(void)
{
	char	*prompt;

	prompt = ft_strdup("minishell$ ");
	return (prompt);
}

char	*display_prompt_and_get_line(void)
{
	char	*prompt;	
	char	*line;

	prompt = get_prompt();
	if (prompt == NULL)
		return (NULL);
	line = readline(prompt);
	free(prompt);
	return (line);
}

char	*read_line(t_shell_data *data)
{
	char	*line;

	line = display_prompt_and_get_line();
	if (line == NULL)
	{
		data->exit_status = ENOMEM;
		return (NULL);
	}
	if (ft_strlen(line) > 0)
		add_history(line);
	return (line);
}
