/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:11:16 by nteechar          #+#    #+#             */
/*   Updated: 2024/05/29 15:34:07 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	is_newline_in_list(t_gnl_list *lst)
{
	char	*str;

	if (lst == NULL)
		return (0);
	while (lst != NULL)
	{
		str = (lst->str) + (lst->i);
		while (*str != '\0')
		{
			if (*str == '\n')
				return (1);
			str++;
		}
		lst = lst->next;
	}
	return (0);
}

static int	keep_reading_to_list(int fd, t_gnl_list **lst)
{
	t_gnl_list	*node;
	ssize_t		chars_read;

	while (1)
	{
		node = gnl_ft_lstnew();
		if (node == NULL)
			return (ERROR);
		chars_read = read(fd, node->str, BUFFER_SIZE);
		if (chars_read == -1)
		{
			gnl_ft_lstdelone(node);
			return (ERROR);
		}
		else if (chars_read == 0)
		{
			gnl_ft_lstdelone(node);
			return (SUCCESS);
		}
		(node->str)[chars_read] = '\0';
		gnl_ft_lstadd_back(lst, node);
		if (is_newline_in_list(node))
			return (SUCCESS);
	}
}

static size_t	get_line_length(t_gnl_list *lst)
{
	size_t	len;
	char	*str;

	len = 0;
	while (lst != NULL)
	{
		str = (lst->str) + (lst->i);
		while (*str != '\0')
		{
			if (*str == '\n')
				return (len + 1);
			len++;
			str++;
		}
		lst = lst->next;
	}
	return (len);
}

static char	*get_line_from_list(t_gnl_list **lst, size_t len)
{
	char	*line;
	size_t	j;

	line = malloc(len + 1);
	if (line == NULL)
		return (NULL);
	line[len] = '\0';
	j = 0;
	while (*lst != NULL)
	{
		while (((*lst)->str)[(*lst)->i] != '\0')
		{
			line[j++] = ((*lst)->str)[((*lst)->i)++];
			if (((*lst)->str)[(*lst)->i - 1] == '\n')
			{
				if (((*lst)->str)[(*lst)->i] == '\0')
					gnl_ft_lstdel_front(lst);
				return (line);
			}
		}
		gnl_ft_lstdel_front(lst);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static t_gnl_list	*head;
	char				*line;
	size_t				line_length;

	if (!is_newline_in_list(head))
	{
		if (keep_reading_to_list(fd, &head) == ERROR)
		{
			gnl_ft_lstclear(&head);
			return (NULL);
		}
	}
	line_length = get_line_length(head);
	if (line_length == 0)
		return (NULL);
	line = get_line_from_list(&head, line_length);
	if (line == NULL)
	{
		gnl_ft_lstclear(&head);
		return (NULL);
	}
	return (line);
}
