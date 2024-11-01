/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:13:31 by nteechar          #+#    #+#             */
/*   Updated: 2024/10/16 18:27:47 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# define WORD 10
# define REDIR 20
# define INFILE 21
# define OUTFILE 22
# define HEREDOC 23
# define APPEND 24
# define PIPE 30

typedef int	t_token_type;

// token class
typedef struct s_token
{
	t_token_type	type;
	char			*str;
}	t_token;

t_token	*create_token(char *str, t_token_type type);
void	*copy_token(void *token);
void	free_token(void *content);

#endif
