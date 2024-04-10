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

int	ft_conversion(const char spec, va_list vargs)
{
	if (spec == 'c')
		return (ft_putchar(va_arg(vargs, int)));
	else if (spec == 'u')
		return (ft_putnbr(va_arg(vargs, unsigned int)));
	else if ((spec == 'i') || (spec == 'd'))
		return (ft_putnbr(va_arg(vargs, int)));
	else if (spec == 's')
		return (ft_putstr(va_arg(vargs, char *)));
	else if (spec == 'x' || spec == 'X')
		return (ft_putnbr_hexa(va_arg(vargs, unsigned int),spec));
	else if (spec == 'p')
		return (ft_putptr(va_arg(vargs, void *)));
	else if (spec == '%')
		return (ft_putchar('%'));
	return (-1);
}

int	ft_printf(char const *format, ...)
{
	va_list	vargs;
	int		len;
	int		check;

	va_start(vargs, format);
	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			check = ft_conversion(*(++format), vargs);
			if (check == -1)
				return (-1);
			len += check;
		}
		else
		{
			if (write(1, format, 1) == -1)
				return (-1);
			len++;
		}
		format++;
	}
	va_end(vargs);
	return (len);
}

int main()
{
	ft_printf("Hello, %s! The answer is %d.\n", "world", 42);
    ft_printf("Unsigned integer: %u\n", 4294967295U);
    ft_printf("Hexadecimal (lowercase): %x\n", 0xABCD1234);
    ft_printf("Hexadecimal (uppercase): %X\n", 0xABCD1234);
    ft_printf("Pointer: %p\n", &main);
    ft_printf("Percent sign: %%\n");
    ft_printf("Character: %c\n", 'A');
    return 0;
}

