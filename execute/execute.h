/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:16:44 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/11/15 02:14:56 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include <stdio.h>
# include <fcntl.h>
# include "../setup/setup.h"
# include "../parse_line/parse_line.h"
# include "../setup/env_var.h"
#  include "../__debugging/__debugging.h"

typedef struct s_execute_command
{
	t_command	*command;
	int			pipe_fds[2];
	int			fd_prev;
	int			fd_in;
	int			fd_out;
	pid_t		pid;
}	t_execute_command;

t_exit_status	main_execute(t_list *command, t_shell_data *envp);

t_list	*init_execute_command_list(t_list *commands);
void	free_execute_command_list(t_list **execute_command_list);

/*redirection input*/
void	redir_input_type_file(t_token *file, t_list *cmd_lst, int type);
void	handle_redirection_input(t_list *cmd_lst);

/*redirection output*/
void	redir_output_type_file(t_token *file, t_list *cmd_lst, int type);
void	handle_redirection_output(t_list *cmd_lst);

/*wait*/
int		wait_allprocess(t_list *cmd_lst);

char	*find_path(char *key, t_list *env_var_lst, char *cmd);
int		check_file(t_list *token);
int		check_path(char *cmd);
int		check_backslash(char *cmd);
void	free_arr(char **arr);
char	*join_path(char **full_path, char *cmd);
int		ft_heredoc(char *delimiter);

#endif
