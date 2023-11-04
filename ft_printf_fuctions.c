/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fuctions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duamarqu <duamarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:05:29 by duamarqu          #+#    #+#             */
/*   Updated: 2023/11/04 20:15:48 by duamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c)
{
	return (write(1, &c, 1));
}

int	print_string(char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
		str = "(null)";
	while (*str)
		count += write(1, str++, 1);
	return (count);
}

int	print_digit(long long i, int base, char *str)
{
	int		count;

	count = 0;
	if (i < 0)
	{
		write(1, "-", 1);
		return (print_digit(-i, base, str) + 1);
	}
	else if (i < (long long)base)
		return (count + print_char(str[i]));
	else
	{
		count += print_digit(i / base, base, str);
		count += print_digit(i % base, base, str);
	}
	return (count);
}

int	print_pointer(unsigned long i, int base, char *str, int id)
{
	int		count;

	count = 0;
	if (id == 2)
	{
		if (i == 0)
			return (write(1, "(nil)", 5));
		count += write(1, "0x", 2);
	}
	if (i < (unsigned long)base)
		return (count + print_char(str[i]));
	else
	{
		count += print_pointer(i / base, base, str, 0);
		count += print_pointer(i % base, base, str, 0);
	}
	return (count);
}
