/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 19:28:14 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/09/04 15:51:14 by pesrisaw         ###   ########.fr       */
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

typedef struct s_simple_cmd
{
	char	**argv;
	t_list	*in;
	t_list	*out;
}	t_simple_cmd;

/*Signal*/
void	setup_signal(void);

#endif