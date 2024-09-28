#include "__debugging.h"

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
		printf("\t"); print_string_arr(command->argv, "command->argv");
		printf("\t"); print_tokens(command->redirs, "command->redirs");
		printf("\n");
		printf(")\n");
		commands = commands->next;
	}
	printf("\n");
}
