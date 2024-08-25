/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:11:08 by nteechar          #+#    #+#             */
/*   Updated: 2024/05/29 15:44:28 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef CONSTANTS
#  define ERROR -1
#  define SUCCESS 0
# endif

# include <unistd.h>
# include <stdlib.h>

char		*get_next_line(int fd);

typedef struct s_gnl_list
{
	char				*str;
	int					i;
	struct s_gnl_list	*next;
}	t_gnl_list;

t_gnl_list	*gnl_ft_lstnew(void);
void		gnl_ft_lstdelone(t_gnl_list *lst);
void		gnl_ft_lstdel_front(t_gnl_list **lst);
void		gnl_ft_lstclear(t_gnl_list **lst);
void		gnl_ft_lstadd_back(t_gnl_list **lst, t_gnl_list *new);

#endif
