/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:50:49 by nteechar          #+#    #+#             */
/*   Updated: 2024/08/26 01:28:11 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#include <readline/readline.h>
#include <readline/history.h>
#include "libft/libft.h"

static int signal_global;

void	sigint_handle(int signal)
{
	if (signal == SIGINT && signal_global == 0)
	{
		rl_on_new_line(); // บอก readline ว่าจะขึ้นบรรทัดใหม่
		printf("\n"); // ขึ้นบรรทัดให้ prompt
		rl_replace_line("", 0); // บรรทัดให้เป็นข้อความว่าง
		rl_redisplay(); // รีหน้า display
		return ;
	}
}

void	signal_handle(int signal)
{
	if (signal == SIGINT)
		sigint_handle(signal);
	else if (signal == SIGQUIT)
	{
		rl_redisplay();
		return ;
	}
}
void	setup_signal(void)
{
	struct sigaction act;

	signal_global = 0;
	ft_memset(&act, 0, sizeof(act));
	act.sa_handler = &signal_handle;
	act.sa_flags =  SA_RESTART;
	sigaction(SIGINT, &act, NULL);
	sigaction(SIGQUIT, &act, NULL);
}

int	main(int argc, char **argv, char **envp)
{
	char	*input;
	char	*const path[] = {"/usr/bin/yes", NULL};
	char	*const env[] = {NULL};
	setup_signal();
	while (1)
	{
		input = readline("minishell> ");
		if (!input)
		{
			free (input);
			break ;
		}
		// printf("input : %s\n", input);
		if (input && ft_strlen(input) > 0)
			add_history(input);
		free(input);
	}
}
