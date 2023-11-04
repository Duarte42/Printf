/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duamarqu <duamarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 09:41:13 by duamarqu          #+#    #+#             */
/*   Updated: 2023/11/04 20:13:13 by duamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	if (i < 0)
	{
		write(1, "-", 1);
		return (print_pointer(-i, base, str, 0) + 1);
	}
	else if (i < (unsigned long)base)
		return (count + print_char(str[i]));
	else
	{
		count += print_pointer(i / base, base, str, 0);
		count += print_pointer(i % base, base, str, 0);
	}
	return (count);
}

int	ft_printf_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += print_char(va_arg(ap, int));
	else if (specifier == 's')
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
