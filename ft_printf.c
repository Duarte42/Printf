/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duamarqu <duamarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 09:41:13 by duamarqu          #+#    #+#             */
/*   Updated: 2023/11/03 16:03:18 by duamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += print_char(va_arg(ap, int));
	else if (specifier == 's' || specifier == 'c')
		count += print_string(va_arg(ap, char *));
	else if (specifier == '%')
		count += print_char('%');
	else if (specifier == 'd' || specifier == 'i')
		count += print_digit(va_arg(ap, int), 10, LOWER);
	else if (specifier == 'u')
		count += print_digit(va_arg(ap, unsigned int), 10, LOWER);
	else if (specifier == 'x')
		count += print_digit(va_arg(ap, unsigned int), 16, LOWER);
	else if (specifier == 'X')
		count += print_digit(va_arg(ap, unsigned int), 16, UPPER);
	else if (specifier == 'p')
		count += print_pointer(va_arg(ap, unsigned long), 16, LOWER, 2);
	else
		count += write(1, &specifier, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
			count += ft_printf_format(*++format, ap);
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);
}

/*int main(void)
{
	void *ptr;

	ptr = 1;
	//ft_printf("-> %d\n", ft_printf("%c", 'c'));
	//ft_printf("-> %d\n", ft_printf("%s", "world"));
	//ft_printf("-> %d\n", ft_printf("%%"));
	//ft_printf("-> %d\n", ft_printf("%d", -42));
	//ft_printf("-> %d\n", ft_printf("%i", -42));
	//ft_printf("-> %d\n", ft_printf("%u", -214));
	//printf("-> %d\n", printf("%u", -214));
	//printf("-> %d\n", ft_printf("%x", -42));
	//ft_printf("-> %d\n", ft_printf("%x", -42));
	//ft_printf("-> %d\n", ft_printf("%X", 9223372036854775807LL));
	//printf("-> %d\n", printf("%X", 9223372036854775807LL));
	//ft_printf("-> %d\n", ft_printf("%p", 1));
	printf("-> %d\n", ft_printf("%p", LONG_MIN));
	//printf("%y\n", "test");
	return (0);
}*/
