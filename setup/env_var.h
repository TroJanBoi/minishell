/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:02:40 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/20 17:51:04 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_VAR_H
# define ENV_VAR_H

# include "../libft/list/t_list.h"
# include "../libft/libft.h"

typedef struct s_env_var
{
	char	*key;
	char	*value;
}	t_env_var;

// env_var_list
t_list		*create_env_var_list(char **envp);
void		free_env_var_list(t_list **env_var_list);

t_list		*find_env_var(char *key, t_list *env_var_list);
t_list		*set_env_var(char *key, char *value, t_list **env_var_list);
void		del_env_var(char *key, t_list **env_var_list);
void		print_env_var_list(t_list *env_var_list);

char		**get_envp(t_list *env_var_list);

// env_var
t_env_var	*create_env_var(char *key, char *value);
void		free_env_var(void *env_var);

// utils
char		**split_env_var_line(char *env_var_line);

#endif
