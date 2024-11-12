/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:31:11 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/12 11:59:44 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "builtin.h"

static void	apply_options(int argc, char **argv, int *i, int *put_newline)
{
	while (*i < argc && ft_strcmp(argv[*i], "-n") == 0)
	{
		*put_newline = FALSE;
		(*i)++;
	}
}

static void	print_stuffs(int argc, char **argv, int *i)
{
	while (*i < argc)
	{
		ft_printf("%s", argv[*i]);
		if (*i < argc - 1)
			ft_printf(" ");
		(*i)++;
	}
}

int	builtin_echo(int argc, char **argv)
{
	int		put_newline;
	int		i;

	put_newline = TRUE;
	i = 1;
	if (i < argc)
	{
		apply_options(argc, argv, &i, &put_newline);
		print_stuffs(argc, argv, &i);
	}
	if (put_newline)
		ft_printf("\n");
	return (SUCCESS);
}
