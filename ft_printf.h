/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duamarqu <duamarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:48:58 by duamarqu          #+#    #+#             */
/*   Updated: 2023/11/03 16:07:48 by duamarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifndef LOWER
#  define LOWER "0123456789abcdef"
# endif
# ifndef UPPER
#  define UPPER "0123456789ABCDEF"
# endif

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_printf_format(char specifier, va_list ap);
int	print_digit(long long i, int base, char *str);
int	print_string(char *str);
int	print_char(char c);
int	print_pointer(unsigned long i, int base, char *str, int id);

#endif
