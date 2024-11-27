/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_signal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:38:43 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/11/27 17:12:35 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "../libft/libft.h"
#include "../builtin/builtin.h"

void	ft_sigint(int signal)
{
	if (signal == SIGINT)
	{
		if (g_signal_global == 1)
			return (ft_putstr_fd("\n", STDOUT_FILENO));
		ft_putstr_fd("\n", STDOUT_FILENO);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	return ;
}

void	ft_sigquit(int signal)
{
	if (signal == SIGQUIT)
	{
		ft_putendl_fd("Quit (core dumped)", STDIN_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
		rl_on_new_line();
		rl_replace_line("", 0);
	}
}

void	setup_signal(void)
{
	struct sigaction	act_int;
	struct sigaction	act_quit;

	sigemptyset(&act_int.sa_mask);
	act_int.sa_handler = &ft_sigint;
	act_int.sa_flags = SA_RESTART;
	sigaction(SIGINT, &act_int, 0);
	
	sigemptyset(&act_quit.sa_mask);
	act_quit.sa_handler = &ft_sigquit;
	act_quit.sa_flags = SA_RESTART;
	sigaction(SIGQUIT, &act_quit, 0);
}
