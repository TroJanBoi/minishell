/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirs_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 02:09:53 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/11/15 02:10:03 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	redir_input_type_file(t_token *file, t_list *cmd_lst, int type)
{
	t_execute_command	*cmd;

	if (file->type != WORD)
		return ;
	cmd = cmd_lst->content;
	if (type == INFILE)
		cmd->fd_in = open(file->str, O_RDONLY);
	else if (type == HEREDOC)
		cmd->fd_in = ft_heredoc(file->str);
	if (cmd->fd_in == -1)
	{
		perror(file->str);
		return ;
	}
}

void	handle_redirection_input(t_list *cmd_lst)
{
	t_list				*redirs;
	t_execute_command	*exe_cmd;
	t_token				*operator;
	t_token				*filename;

	exe_cmd = cmd_lst->content;
	redirs = exe_cmd->command->redirs;
	while (redirs->content)
	{
		operator = redirs->content;
		if (operator->type == INFILE || operator->type == HEREDOC)
		{
			redirs = redirs->next;
			filename = redirs->content;
			redir_input_type_file(filename, cmd_lst, operator->type);
		}
		redirs = redirs->next;
	}
	dup2(exe_cmd->fd_in, STDIN_FILENO);
	close(exe_cmd->fd_in);
}
