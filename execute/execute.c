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
	pl->redir_in[0] = ft_strdup("infile1.txt");
	pl->redir_in[1] = ft_strdup("Mode");

	pl->redir_out = malloc(sizeof(char *) * 2);
	pl->redir_out[0] = ft_strdup("outfile-1");
	pl->redir_out[1] = ft_strdup("Mode");

	return (pl);
}

int		check_access_file(char *filename)
{
	if ((access(filename, R_OK) == 0) || (access(filename, R_OK | W_OK)) == 0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int		check_all_redir_in(t_list *pipeline, t_simple_command *cmd_one)
{
	int	i;

	i = 0;
	while (cmd_one->redir_in[i])
	{
		if (check_access_file(cmd_one->argv[i]) == 1)
		{
			ft_putstr_fd(cmd_one->redir_in[i], 2);
			perror(PURPLE_TEXT"\naccess failed"RESET_TEXT);
			exit (EXIT_FAILURE);
		}
		i += 2;
	}
	return (EXIT_SUCCESS);
}

void	exe_cute(char **envp, t_simple_command *cmd_one)
{
	// t_simple_command	*cmd_one = test_init_one();

	if (execve(cmd_one->argv[0], cmd_one->argv, envp) == -1)
	{
		perror(RED_TEXT"execute failed"RESET_TEXT);
		exit(EXIT_FAILURE);
	}
}

void	process(t_list *pipeline, char **envp, t_exe *data, t_simple_command *cmd_one)
{
	int	fdin;

	if (check_all_redir_in(pipeline, cmd_one) == 0)
	{
		fdin = open(cmd_one->redir_in[0], O_RDONLY);
		if (fdin < 0)
			perror(PURPLE_TEXT"open fail"RESET_TEXT);
		dup2(fdin, STDIN_FILENO);
		close(fdin);
	}
	exe_cute(envp, cmd_one);
}

void	init_execute(t_list **pipeline, t_exe *data, char **envp, t_simple_command *cmd)
{
	if (pipe(data->fd) == -1)
		perror(RED_TEXT"pipe failed"RESET_TEXT);
	data->pid = fork();
	if (data->pid < 0)
		perror(RED_TEXT"fork failed"RESET_TEXT);
	if (data->pid == 0)
		process(*pipeline, envp, data, cmd);
	wait(NULL);
	close(data->fd[0]);
	close(data->fd[1]);
	
}

void	execute(t_list *pipeline, char **envp)
{
	t_exe	data;
	t_simple_command *cmd_one = test_init_one();
	t_simple_command *cmd_two = test_init_two();
	t_simple_command arr[2] = {*cmd_one, *cmd_two};

	printf(GREEN_TEXT"start execute\n"RESET_TEXT);
	int	i = 0;

	while (i < 2)
	{
		dprintf(2, YELLOW_TEXT"i : %d\n"RESET_TEXT, i);
		init_execute(&pipeline, &data, envp, &arr[i]);
		i++;
	}
	// if (pipe(data.fd) == -1)
	// 	perror("pipe failed");
	// data.pid = fork();
	// if (data.pid < 0)
	// 	perror("fork failed");
	// else if (data.pid == 0)
	// 	process(pipeline, envp, &data);
	// waitpid(data.pid, NULL, 0);
	// close(data.fd[0]);
	// close(data.fd[1]);
	printf(GREEN_TEXT"exit execute\n"RESET_TEXT);
}
