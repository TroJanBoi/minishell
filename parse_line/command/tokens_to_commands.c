/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_to_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:07:38 by nteechar          #+#    #+#             */
/*   Updated: 2024/09/20 16:33:58 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse_line.h"

int		handle_tokens(t_list **tokens, t_list **commands, t_list **temp_argv,
			t_list **temp_redirs);
char	**tokens_to_argv(t_list *temp_argv);
t_list	*tokens_to_redirs(t_list *temp_redirs);

// part of add_command function
static t_command	*create_command(t_list **temp_argv, t_list **temp_redirs)
{
	t_command	*command;

	command = malloc(sizeof(t_command));
	if (command == NULL)
		return (NULL);
	command->redirs = tokens_to_redirs(*temp_redirs);
	if (command->redirs == NULL)
	{
		free(command);
		return (NULL);
	}
	command->argv = tokens_to_argv(*temp_argv);
	if (command->argv == NULL)
	{
		ft_lstclear(&command->redirs, free_token);
		free(command);
		return (NULL);
	}
	return (command);
}

// cleanup temp_argv and temp_redirs only if successful
int	add_command(t_list **commands, t_list **temp_argv, t_list **temp_redirs)
{
	t_command	*command;

	command = create_command(temp_argv, temp_redirs);
	if (command == NULL)
		return (ERROR);
	if (ft_lstnew_add_back(commands, command) == NULL)
	{
		free_command(command);
		return (ERROR);
	}
	ft_lstclear(temp_argv, free_token);
	ft_lstclear(temp_redirs, free_token);
	return (SUCCESS);
}

static void	tokens_to_commands_cleanup(t_list **commands, t_list **temp_argv,
	t_list **temp_redirs)
{
	ft_lstclear(commands, free_command);
	ft_lstclear(temp_argv, free_token);
	ft_lstclear(temp_redirs, free_token);
}

t_list	*tokens_to_commands(t_list *tokens)
{
	t_list	*commands;
	t_list	*temp_argv;
	t_list	*temp_redirs;

	commands = NULL;
	temp_argv = NULL;
	temp_redirs = NULL;
	while (tokens)
	{
		if (handle_tokens(&tokens, &commands, &temp_argv, &temp_redirs)
			!= SUCCESS)
		{
			tokens_to_commands_cleanup(&commands, &temp_argv, &temp_redirs);
			return (NULL);
		}
	}
	if (add_command(&commands, &temp_argv, &temp_redirs) != SUCCESS)
	{
		tokens_to_commands_cleanup(&commands, &temp_argv, &temp_redirs);
		return (NULL);
	}
	return (commands);
}
