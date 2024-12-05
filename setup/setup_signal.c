/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_signal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:38:43 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/11/27 15:32:52 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "../libft/libft.h"
#include "../builtin/builtin.h"

static void	ft_sigint(int signal)
{
	if (signal != SIGINT)
		return ;
	if (g_signal_global == READ_MODE)
	{
		ft_putstr_fd("\n^C\n", STDOUT_FILENO);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	else
	{
		ft_putstr_fd("^C\n", STDOUT_FILENO);
	}
}

static void	ft_sigquit(int signal)
{
	if (signal != SIGQUIT)
		return ;
	if (g_signal_global == READ_MODE)
	{
		rl_replace_line("", 0);
        rl_on_new_line();
        rl_redisplay();
	}
	else
	{
		ft_putstr_fd("^\\Quit (core dumped)\n", STDIN_FILENO);
		rl_replace_line("", 0);
		rl_on_new_line();
	}
}

static void	set_signal_handler(struct sigaction *act,
	void (*func)(int), int signal)
{
	ft_bzero(act, sizeof(struct sigaction));
	sigemptyset(&act->sa_mask);
	act->sa_handler = func;
	act->sa_flags = SA_RESTART;
	sigaction(signal, act, 0);
}

void	setup_signal(void)
{
	struct sigaction	act_int;
	struct sigaction	act_quit;

	set_signal_handler(&act_int, ft_sigint, SIGINT);
	set_signal_handler(&act_quit, ft_sigquit, SIGQUIT);
}
