/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_func.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:39:29 by nteechar          #+#    #+#             */
/*   Updated: 2024/10/25 17:36:51 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTERNAL_FUNC_H
# define EXTERNAL_FUNC_H

/*
readline, rl_clear_history, rl_on_new_line, 
rl_replace_line, rl_redisplay, add_history,

printf, malloc, free, write, access, open, read, close,

fork, wait, waitpid, wait3, wait4,
signal, sigaction, sigemptyset, sigaddset, kill, exit,

getcwd, chdir,

stat, lstat, fstat, unlink,

execve, dup, dup2, pipe,

opendir, readdir, closedir,

strerror, perror,

isatty, ttyname, ttyslot, ioctl,getenv, tcsetattr, tcgetattr,
tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs
*/

# include <errno.h>

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>

# include <readline/readline.h>
# include <readline/history.h>

#endif
