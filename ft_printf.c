/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:38:02 by hheng             #+#    #+#             */
/*   Updated: 2024/03/22 13:07:05 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_lower(unsigned long long n)
{
	int i;
	char hexa_lower[] = "0123456789abcdef";

	i = 0;
	while (n > 0)
	{
		int remainder = n % 16;
		if (remainder < 10)
			i += ft_putchar(remainder + '0');
		else 
			i += ft_putchar(hexa_lower[remainder - 10]);
		n /= 16;
	}
	return (i);
}

int	hex_upper(unsigned long long n)
{
	int i;
	char hexa_upper[] = "0123456789ABCDEF";

	i = 0;
	while (n > 0)
	{
		int remainder = n % 16;
		if (remainder < 10)
			i += ft_putchar(remainder + '0');
		else 
			i += ft_putchar(hexa_upper[remainder - 10]);
		n /= 16;
	}
	return (i);
}

int	print_pointer(unsigned long long p)
{
	int	i;

	i = 0;
	i += ft_putstr("0x");
	i += hex_lower(p);
	return (i);
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
		a += hexdecimal_l(va_arg(args, unsigned int));
	else if (format == 'X')
		a += hexdecimal_u(va_arg(args, unsigned int));
	else if (format == 'p')
		a += printf_pointer(va_arg(args, unsigned long long));
	return (a);
}

// int	ft_printf(const char *format, ...)
// {
// 	int		a;
// 	va_list	args;

// 	va_start(args, format);
// 	a = 0;
// 	while (*format != '\0')
// 	{
// 		if (*format == '%')
// 		{
// 			format++;
// 			a = printf_specifiers(args, *format, a);
// 		}
// 		else
// 			a += write(1, format, 1);
// 		format++;
// 	}
// 	va_end(args);
// 	return (a);
// }
// */

   int main() {
    // Test value
    unsigned long long test_value = 27;

    // Print lowercase hexadecimal representation
    printf("Lowercase hexadecimal representation: ");
    hex_lower(test_value);
    printf("\n");

    // Print uppercase hexadecimal representation
    printf("Uppercase hexadecimal representation: ");
    hex_upper(test_value);
    printf("\n");

    return 0;
}
