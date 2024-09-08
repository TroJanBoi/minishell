/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:53:53 by nteechar          #+#    #+#             */
/*   Updated: 2024/09/03 17:47:05 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "../libft/libft.h"

typedef enum e_token_type
{
	WORD,
	REDIR_IN,
	REDIR_OUT,
	HEREDOC,
	REDIR_APPEND,
	PIPE
}	t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*str;
}	t_token;

typedef struct s_simple_command
{
	char	**argv;
	char	**redir_in;
	char	**redir_out;
	int		allin;
	int		allout;
	int		fd_in;
	int		fd_out;
}	t_simple_command;

t_list	*parse_line(char *line);
t_list	*tokenize(char *line);
void	expand(t_list *tokens);
t_list	*parse_tokens(t_list *tokens);

#endif
