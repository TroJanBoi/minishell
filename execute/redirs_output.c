/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirs_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 02:12:09 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/11/15 02:12:19 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	redir_output_type_file(t_token *file, t_list *cmd_lst, int type)
{
	t_execute_command	*cmd;
	int 				mode;

	if (file->type != WORD)
		return ;
	if (type == APPEND)
		mode = O_WRONLY | O_CREAT | O_APPEND;
	else
		mode = O_WRONLY | O_CREAT | O_TRUNC;
	cmd = cmd_lst->content;
	cmd->fd_out = open(file->str, mode, 0644);
	if (cmd->fd_out == -1)
	{
		perror("failed file descriptor");
		exit(EXIT_FAILURE);
	}
	dup2(cmd->fd_out, STDOUT_FILENO);
	close(cmd->fd_out);
}

void	handle_redirection_output(t_list *cmd_lst)
{
	t_list				*redirs;
	t_token				*operator;
	t_token				*filename;
	t_execute_command	*exe_cmd;

	exe_cmd = cmd_lst->content;
	redirs = exe_cmd->command->redirs;
	while (redirs->content)
	{
		operator = redirs->content;
		if (operator->type == OUTFILE || operator->type == APPEND)
		{
			if (operator->type == OUTFILE) dprintf(2, "%s>>>> Output Mode <<<<%s\n", YELLOW, RESET);
			else dprintf(2, "%s>>>> Append Mode <<<<%s\n", YELLOW, RESET);

			redirs = redirs->next;
			filename = redirs->content;
			redir_output_type_file(filename, cmd_lst, operator->type);
		}
		redirs = redirs->next;
	}
}
