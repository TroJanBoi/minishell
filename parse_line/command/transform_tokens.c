/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_tokens.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:54:02 by nteechar          #+#    #+#             */
/*   Updated: 2024/09/20 14:03:56 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse_line.h"

static void	tokens_to_argv_cleanup(char **argv, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(argv[j]);
		j++;
	}
	free(argv);
}

char	**tokens_to_argv(t_list *temp_argv)
{
	size_t	n;
	size_t	i;
	char	**argv;
	t_token	*token;

	n = ft_lstsize(temp_argv);
	argv = malloc((n + 1) * sizeof(char *));
	if (argv == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		token = temp_argv->content;
		argv[i] = ft_strdup(token->str);
		if (argv[i] == NULL)
		{
			tokens_to_argv_cleanup(argv, i);
			return (NULL);
		}
		i++;
		temp_argv = temp_argv->next;
	}
	argv[i] = NULL;
	return (argv);
}

t_list	*tokens_to_redirs(t_list *temp_redirs)
{
	t_list	*redirs;

	redirs = NULL;
	if (temp_redirs)
	{
		redirs = ft_lstmap(temp_redirs, copy_token, free_token);
		if (redirs == NULL)
			return (NULL);
	}
	if (ft_lstnew_add_back(&redirs, NULL) == NULL)
	{
		ft_lstclear(&redirs, free_token);
		return (NULL);
	}
	return (redirs);
}
