/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duamarqu <duamarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 09:41:13 by duamarqu          #+#    #+#             */
/*   Updated: 2023/10/31 16:25:24 by duamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int	print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	print_string(char *str)
{
	int	count;

	count = 0;
	while(*str)
		count += write(1, str++, 1);
	return (count);
}

int print_digit(int i, int base, char *str)
{
	int	count;

	if (i < 0)
	{
		print_char('-');
		return print_digit(-i, base, str) + 1;
	}
	if (i < base)
		return print_char(str[i]);
	else
	{
		count = print_digit(i / base, base, str);
		return (count + print_digit(i % base, base, str));
	}
}

int	ft_printf_format(char specifier, va_list ap)
{
	int	count;
	char	*lower;
	char	*upper;

	lower = "0123456789abcdef";
	upper = "0123456789ABCDEF";

	count = 0;
	if(specifier == 'c')
		count += print_char(va_arg(ap, int));
	else if(specifier == 's')
		count += print_string(va_arg(ap, char *));
	else if(specifier == '%')
		count += print_char('%');
	else if(specifier == 'd')
		count += print_digit(va_arg(ap, int), 10, lower);
	else if(specifier == 'i')
		count += print_digit(va_arg(ap, int), 10, lower);
	else if (specifier == 'u')
		count += print_digit(va_arg(ap, unsigned int), 10, lower);
	else if (specifier == 'x')
		count += print_digit(va_arg(ap, unsigned int), 16, lower);
	else if (specifier == 'X')
		count += print_digit(va_arg(ap, unsigned int), 16, upper);
	else
		print_string("NO SPECIFIER FOUND");
	return (count);

}

int ft_printf(const char *format, ...)
{
	va_list ap;
	int	count;

	va_start(ap, format);
	count = 0;
	while(*format)
	{
		if(*format == '%')
			count += ft_printf_format(*++format, ap);
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);
}

int main()
{
	ft_printf("c -> %c\n", 'C');
	ft_printf("s -> %s\n", "world");
	ft_printf("-> %%\n");
	ft_printf("d -> %d\n", -42);
	ft_printf("i -> %i\n", 42);
	ft_printf("u -> %u\n", -42);
	printf("u_org -> %u\n", -42);
	printf("x_org -> %x\n", -42);
	ft_printf("x -> %x\n", -42);
	ft_printf("X -> %X\n", -42);
	//printf("%y\n", "test");
	return (0);
}
