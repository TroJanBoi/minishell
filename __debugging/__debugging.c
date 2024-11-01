/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __debugging.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:36:11 by nteechar          #+#    #+#             */
/*   Updated: 2024/10/29 17:56:00 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../parse_line/parse_line.h"
#include "colors.h"
#include "../execute/t_exe.h"

void	print_tokens(t_list *tokens, char *var_name)
{
	t_token	*token;

	if (tokens == NULL)
	{
		printf("%s%s == NULL%s\n", RED, var_name, RESET);
		return ;
	}
	printf("%s = ", var_name);
	while (tokens)
	{
		token = tokens->content;
		if (token == NULL)
		{
			printf("(NULL)---");
			break ;
		}
		printf("(token(%i, %s))---", token->type, token->str);
		tokens = tokens->next;
	}
	printf("\n");
}

void	print_string_arr(char **arr, char *var_name)
{
	printf("%s = [ ", var_name);
	while (*arr)
	{
		printf("%s | ", *arr);
		arr++;
	}
	printf("NULL ]");
	printf("\n");
}

void	print_string_list(t_list *strings, char *var_name)
{
	printf("%s = ", var_name);
	while (strings)
	{
		printf("(%s)---", (char *) strings->content);
		strings = strings->next;
	}
	printf("\n");
}

void	print_commands(t_list *commands)
{
	t_command	*command;

	if (commands == NULL)
	{
		printf("%scommands == NULL%s\n", RED, RESET);
		return ;
	}
	printf("commands = \n");
	while (commands)
	{
		command = commands->content;
		printf("(\n");
		print_string_arr(command->argv, "\tcommand->argv");
		print_tokens(command->redirs, "\tcommand->redirs");
		printf("\n");
		printf(")\n");
		commands = commands->next;
	}
	printf("\n");
}

void	print_commands_exe(t_exe *exe_list)
{
	t_command	*command;

	while (exe_list)
	{
		command = exe_list->command;
		printf("Command: ");
		print_string_arr(command->argv, "command->argv");
		print_tokens(command->redirs, "command->redirs");
		exe_list = exe_list->next;
	}
}
