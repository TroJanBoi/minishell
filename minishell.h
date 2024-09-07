/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 19:28:14 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/09/05 01:31:29 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define SUCCESS_EXE 0
# define CATCH_ERROR 1
# define IMPROPER_CMD 2
# define ISSUE_PATH 127
# define FATAL_ERROR 130
# define OUT_RANGE 255

# define RED_TEXT "\033[0;31m"
# define GREEN_TEXT "\033[0;32m"
# define YELLOW_TEXT "\033[0;33m"
# define BLUE_TEXT "\033[0;34m"
# define PURPLE_TEXT "\033[0;35m"
# define CYAN_TEXT "\033[0;36m"
# define RESET_TEXT "\033[0m"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"
# include "parse/parse.h"

/*Signal*/
void	setup_signal(void);
/*Execute*/
void	execute(t_list *pipeline, char **envp);

#endif