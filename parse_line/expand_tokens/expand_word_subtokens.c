/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_word_subtokens.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:23:47 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/07 18:43:34 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../token/token.h"

static void	handle_quote(char *str, int *expand_vars)
{
	if (ft_strcmp(str, "\'") == 0)
	{
		if (*expand_vars)
			*expand_vars = FALSE;
		else
			*expand_vars = TRUE;
	}
}

// TODO: replace with our own ft_getenv???
static char	*get_new_str(char *str, int expand_vars)
{
	char	*env_value;

	if (str[0] == '$' && expand_vars)
	{
		env_value = getenv(((char *) str) + 1);
		if (env_value)
			return (ft_strdup(env_value));
		else
			return (ft_strdup(""));
	}
	return (ft_strdup(str));
}

static int	handle_string(char *str, int expand_vars, t_list **new_subtokens)
{
	char	*new_str;

	new_str = get_new_str(str, expand_vars);
	if (new_str == NULL || !ft_lstnew_add_back(new_subtokens, new_str))
	{
		ft_lstclear(new_subtokens, free);
		return (ERROR);
	}
	return (SUCCESS);
}

t_list	*expand_word_subtokens(t_list *subtokens)
{
	t_list	*new_subtokens;
	int		expand_vars;
	char	*str;

	new_subtokens = NULL;
	expand_vars = TRUE;
	while (subtokens)
	{
		str = subtokens->content;
		if (ft_strcmp(str, "\'") == 0 || ft_strcmp(str, "\"") == 0)
			handle_quote(str, &expand_vars);
		else
		{
			if (handle_string(str, expand_vars, &new_subtokens) != SUCCESS)
				return (NULL);
		}
		subtokens = subtokens->next;
	}
	return (new_subtokens);
}
