/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:38:02 by hheng             #+#    #+#             */
/*   Updated: 2024/04/09 18:49:01 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_hex_l(unsigned long long n)
{
	int charCount = 0;

    if (n >= 16) {
        charCount += printf_hex_l(n / 16);
        charCount += printf_hex_l(n % 16);
    }

    else {
        if (n < 10) {
            charCount += ft_putchar(n + '0');
        }
        else {
            charCount += ft_putchar(n + 'a' - 10);
        }
    }
    return charCount;
}

int	printf_hex_u(unsigned long long n)
{
	int charCount = 0;

    if (n >= 16) {
        charCount += printf_hex_u(n / 16);
        charCount += printf_hex_u(n % 16);
    }
    else {
        if (n < 10) {
            charCount += ft_putchar(n + '0');
        }
        else {
            charCount += ft_putchar(n + 'A' - 10);
        }
    }
    return charCount;
}

int	printf_pointer(unsigned long long p)
{
	int charCount = 0;

    charCount += ft_putstr("0x");

    charCount += printf_hex_l(p);

    return charCount;
}

int	printf_specifiers(va_list args, char format, int a)
{
	if (format == 'd')
		a += ft_putnbr(va_arg(args, int));
	else if (format == 's')
		a += ft_putstr(va_arg(args, char *));
	else if (format == 'c')
		a += ft_putchar(va_arg(args, int));
	else if (format == '%')
		a += ft_putchar(37);
	else if (format == 'i')
		a += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		a += ft_putnbr_u(va_arg(args, unsigned int));
	else if (format == 'x')
		a += printf_hex_l(va_arg(args, unsigned int));
	else if (format == 'X')
		a += printf_hex_u(va_arg(args, unsigned int));
	else if (format == 'p')
		a += printf_pointer(va_arg(args, unsigned long long));
	return (a);
}

int	ft_printf(const char *format, ...)
{
	int		a;
	va_list	args;

	va_start(args, format);
	a = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			a = printf_specifiers(args, *format, a);
		}
		else
			a += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (a);
}

