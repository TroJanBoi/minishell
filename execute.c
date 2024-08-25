/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 13:33:15 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/07/27 16:29:31 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
#include <sched.h>
#include <signal.h>
#include <time.h>

void	child_process(char *av, char **env)
{
	int		fd[2];
	pid_t	child;
	char	*cmd[] = {av, NULL, NULL};

	printf("cmd : %s\n", av);
	if (pipe(fd) == -1)
	{
		perror("pipe");
		exit (0);
	}
	child = fork();
	if (child == 0)
	{
		close(fd[1]);
		// printf("chlid : %d\n", child);
		dup2(fd[0], STDERR_FILENO);
		execve(av, NULL, env);
	}
	// printf("parent : %d\n", child);
	wait(NULL);
}

int	main(int ac, char **av, char **envp)
{
	int		i;

	i = 1;
	while (i < ac)
		child_process(av[i++], envp);
}
