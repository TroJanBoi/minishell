#ifndef __DEBUGGING_H
# define __DEBUGGING_H

# include "minishell.h"

void	print_tokens(t_list *tokens, char *var_name);
void	print_string_arr(char **arr, char *var_name);
void	print_commands(t_list *commands);

#endif
