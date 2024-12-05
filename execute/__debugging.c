/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __debugging.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:36:11 by nteechar          #+#    #+#             */
/*   Updated: 2024/12/05 14:18:25 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execute/execute.h"

void	print_tokens(t_list *tokens, char *var_name)
{
	t_token	*token;

	if (tokens == NULL)
	{
		printf("%s == NULL\n", var_name);
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
		printf("((%i, %s))---", token->type, token->str);
		tokens = tokens->next;
	}
	printf("\n");
}

void	print_string_arr(char **arr, char *var_name)
{
	printf("%s = [", var_name);
	while (*arr)
	{
		printf("%s|", *arr);
		arr++;
	}
	printf("NULL]");
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
		printf("commands == NULL\n");
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

void	print_execute_commands(t_list *exe_list)
{
	t_execute	*exe_cmd;

	while (exe_list)
	{
		exe_cmd = exe_list->content;
		printf("Command: ");
		print_string_arr(exe_cmd->command->argv, "command->argv");
		print_tokens(exe_cmd->command->redirs, "command->redirs");
		exe_list = exe_list->next;
	}
}