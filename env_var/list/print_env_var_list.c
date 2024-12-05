/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env_var_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:45:22 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/26 12:41:53 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../env_var.h"

void	print_env_var_list(t_env_var_list *env_var_list)
{
	t_env_var	*var;

	while (env_var_list)
	{
		var = env_var_list->content;
		printf("%s=%s\n", var->key, var->value);
		env_var_list = env_var_list->next;
	}
}
