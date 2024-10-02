/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 21:46:02 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/10/03 01:12:27 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int check_file(t_list *tokens)
{
    t_token *token;

    if (tokens->content == NULL)
        return (TRUE);

    while (tokens)
    {
        token = (t_token *)tokens->content;

		if (token->type == WORD)
		{
        	// printf("Checking file: %s\n", token->str);
			if (access(token->str, R_OK) == 0 || access(token->str, R_OK | W_OK) == 0)
				return (TRUE);
			else
				return (FALSE);
			tokens = tokens->next;
		}
        tokens = tokens->next;
    }
	printf("%sEND%s\n", PURPLE, RESET);
    return (TRUE);
}

