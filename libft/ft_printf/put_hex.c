/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:11:33 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/03 14:37:24 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// only takes 0 <= n <= 15
static char	convert_to_upper_hex(unsigned int n)
{
	if (n <= 0 && n <= 9)
		return (n + '0');
	else
		return (n - 10 + 'A');
}

// only takes 0 <= n <= 15
static char	convert_to_lower_hex(unsigned int n)
{
	if (n <= 0 && n <= 9)
		return (n + '0');
	else
		return (n - 10 + 'a');
}

// put_uppercase == 0 --> put lower hexadecimal
// put_uppercase != 0 --> put upper hexadecimal
unsigned int	put_hex(size_t n, int put_uppercase)
{
	unsigned int	length_printed;
	char			hex_char;

	length_printed = 0;
	if (n >= 16)
		length_printed += put_hex(n / 16, put_uppercase);
	if (put_uppercase)
		hex_char = convert_to_upper_hex(n % 16);
	else
		hex_char = convert_to_lower_hex(n % 16);
	length_printed += put_char(hex_char);
	return (length_printed);
}
