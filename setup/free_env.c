/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:48:07 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/11/20 17:49:48 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_var.h"

void	free_env_var_list(t_list **env_var_list)
{
	ft_lstclear(env_var_list, free_env_var);
}
