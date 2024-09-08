/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:31:39 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/09/07 17:45:14 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

t_simple_command	*test_init_one(void)
{
	t_simple_command	*pl;

	pl = malloc(sizeof(t_simple_command));
	pl->argv = malloc(sizeof(char *) * 3);
	pl->argv[0] = ft_strdup("/bin/ls");
	pl->argv[1] = NULL;

	pl->redir_in = malloc(sizeof(char *) * 4);
	pl->redir_in[0] = ft_strdup("infile1.txt");
	pl->redir_in[1] = ft_strdup("Mode");
	pl->redir_in[2] = ft_strdup("infile2.txt");
	pl->redir_in[3] = ft_strdup("Mode");

	pl->redir_out = malloc(sizeof(char *) * 2);
	pl->redir_out[0] = ft_strdup("outfile1.txt");
	pl->redir_out[1] = ft_strdup("Mode");

	pl->allin = 2;
	pl->allout = 1;
	pl->fd_in = 0;
	pl->fd_out = 1;
	return (pl);
}

t_simple_command	*test_init_two(void)
{
	t_simple_command	*pl;

	pl = malloc(sizeof(t_simple_command));
	pl->argv = malloc(sizeof(char *) * 2);
	pl->argv[0] = ft_strdup("/usr/bin/cat");
	pl->argv[1] = ft_strdup("-e");

	pl->redir_in = malloc(sizeof(char *) * 2);
	// pl->redir_in[0] = ft_strdup("infile1.txt");
	// pl->redir_in[1] = ft_strdup("Mode");

	pl->redir_out = malloc(sizeof(char *) * 2);
	// pl->redir_out[0] = ft_strdup("outfile-1");
	// pl->redir_out[1] = ft_strdup("Mode");

	pl->allin = 0;
	pl->allout = 0;
	pl->fd_in = 0;
	pl->fd_out = 1;
	return (pl);
}

t_simple_command	*test_init_three(void)
{
	t_simple_command	*pl;

	pl = malloc(sizeof(t_simple_command));
	pl->argv = malloc(sizeof(char *) * 2);
	pl->argv[0] = ft_strdup("/usr/bin/cat");
	pl->argv[1] = NULL;

	pl->redir_in = malloc(sizeof(char *) * 2);
	pl->redir_in[0] = ft_strdup("infile1.txt");
	pl->redir_in[1] = ft_strdup("Mode");

	pl->redir_out = malloc(sizeof(char *) * 2);
	pl->redir_out[0] = ft_strdup("outfile-1");
	pl->redir_out[1] = ft_strdup("Mode");

	pl->allin = 1;
	pl->allout = 1;
	pl->fd_in = 0;
	pl->fd_out = 1;
	return (pl);
}

void	init_execute(t_list *pipeline, char **envp)
{
	
}

void	check_infile(t_list *pipeline, t_simple_command *cmd)
{
	int	i;

	i = 0;
	dprintf(2, PURPLE_TEXT"all infile : %d\n"RESET_TEXT, cmd->allin);
	while (i < cmd->allin)
	{
		if (access(cmd->redir_in[i]))
		i += 2;
	}
}

void	execute2(t_list *pipeline, char **envp, t_simple_command *cmd)
{
	// dprintf(2, PURPLE_TEXT"cmd : %s\n"RESET_TEXT, cmd->argv[0]);
	check_infile(pipeline, cmd);
}

void	execute(t_list *pipeline, char **envp)
{
	t_simple_command *cmd_one = test_init_one();
	t_simple_command *cmd_two = test_init_two();
	t_simple_command *cmd_three = test_init_three();
	t_simple_command cmd[3] = {*cmd_one, *cmd_two, *cmd_three};
	int	i;
	dprintf(2, GREEN_TEXT"start execute\n"RESET_TEXT);
	i = 0;
	while (i < 3)
	{
		// dprintf(2, PURPLE_TEXT"cmd : %s\n"RESET_TEXT, cmd[i].argv[0]);
		execute2(pipeline, envp, &cmd[i]);
		i++;
	}
	dprintf(2, GREEN_TEXT"stoop execute\n"RESET_TEXT);
}