/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 19:28:14 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/09/30 15:25:53 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// allowed headers

/*ALLOWED FUNCTIONS
readline, rl_clear_history, rl_on_new_line,
rl_replace_line, rl_redisplay, add_history,

printf, malloc, free, write, access, open, read, close,

fork, wait, waitpid, wait3, wait4, signal,sigaction, sigemptyset,
sigaddset, kill, exit,

getcwd, chdir,

stat, lstat, fstat, unlink,

execve, dup, dup2, pipe, 

opendir, readdir, closedir,

strerror, perror,

isatty, ttyname, ttyslot, ioctl,getenv, tcsetattr, tcgetattr,
tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs
*/
# include <unistd.h>
# include <stdlib.h>

# include <stdio.h>
# include <string.h>

# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>

# include <readline/readline.h>
# include <readline/history.h>

# include <errno.h>

// our headers
# include "libft/libft.h"
# include "constants.h"

// program's headers
# include "parse_line/parse_line.h"

// execute
# include  "execute/execute.h"

#include "__debugging.h"
#include "colors.h"

/*Signal*/
// void	setup_signal(void);

#endif
