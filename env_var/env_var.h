/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:02:40 by nteechar          #+#    #+#             */
/*   Updated: 2024/10/29 17:43:17 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_VAR_H
# define ENV_VAR_H

typedef struct s_env_var
{
	char	*key;
	char	*value;
}	t_env_var;

t_env_var	*process_key_value_line(char *line);
void		free_env_var(void *var);

#endif
