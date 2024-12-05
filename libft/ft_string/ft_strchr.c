/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:03:30 by nteechar          #+#    #+#             */
/*   Updated: 2024/12/02 18:13:04 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strchr(const char *s, int c)
{
	char	c_;

	c_ = (char) c;
	while (1)
	{
		if (*s == c_)
			return ((char *) s);
		if (*s == '\0')
			break ;
		s++;
	}
	return (NULL);
}
