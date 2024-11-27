/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:13:31 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/15 16:59:58 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# define OUTSIDE 0
# define INSIDE_SINGLE_QUOTE 1
# define INSIDE_DOUBLE_QUOTE 2

typedef enum e_subtoken_type
{
	SINGLE_QUOTE,
	DOUBLE_QUOTE,
	VARIABLE,
	EXIT_STATUS,
	NORMAL
}	t_subtoken_type;

typedef enum e_token_type
{
	WORD = 10,
	REDIR = 20,
	INFILE = 21,
	OUTFILE = 22,
	HEREDOC = 23,
	APPEND = 24,
	PIPE = 30
}	t_token_type;

typedef struct s_token
{
	int		type;
	char	*str;
}	t_token;

t_token	*create_token(char *str, int type);
void	*copy_token(void *token);
void	free_token(void *content);

int		is_redir(t_token_type type);

#endif
