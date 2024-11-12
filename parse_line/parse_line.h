/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:39:48 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/12 15:01:48 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_LINE_H
# define PARSE_LINE_H

# include "../setup/setup.h"

# include "token/token.h"
# include "command/command.h"

t_list	*parse_line(char *line, t_shell_data *data);

t_list	*tokenize_line(char *line);
t_list	*expand_tokens(t_list *tokens);
int		is_grammar_correct(t_list *tokens);
t_list	*tokens_to_commands(t_list *tokens);

#endif
