/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:38:43 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/10/29 17:35:57 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO: try to make red underlines gone

#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "../libft/libft.h"

int		g_signal_global;

void	ft_sigint(int signal)
{
	if (signal == SIGINT && g_signal_global == 0)
	{
		rl_on_new_line();
		ft_putstr_fd("\n", STDOUT_FILENO);
		rl_replace_line("", 0);
		rl_redisplay();
	}
	return ;
}

void	setup_signal(void)
{
	struct sigaction	act_int;
	struct sigaction	act_quit;

	sigemptyset(&act_int.sa_mask);
	act_int.sa_handler = &ft_sigint;
	act_int.sa_flags = SA_RESTART;
	sigaction(SIGINT, &act_int, NULL);
	sigemptyset(&act_int.sa_mask);
	act_quit.sa_handler = SIG_IGN;
	act_quit.sa_flags = SA_RESTART;
	sigaction(SIGQUIT, &act_quit, NULL);
}
