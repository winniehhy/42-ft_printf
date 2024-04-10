/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:38:05 by hheng             #+#    #+#             */
/*   Updated: 2024/03/21 19:38:04 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int ft_putnbr(long number) {
    long digit;
    int length;
    int result;

    length = 0;

    if (number < 0) {
        if (write(1, "-", 1) == -1)
            return -1;
        length += 1;
        number *= -1;
    }

    digit = number % 10 + '0';

    if (number > 9) {
        result = ft_putnbr(number / 10);
        if (result == -1)
            return -1;
        length += result;
    }

    if (write(1, &digit, 1) == -1)
        return -1;

    length += 1;
    return (length);
}

int ft_putnbr_hexa(unsigned long number, char uppercase) 
{
    int length;
    int remainder;
    char *base;
    int result;

    remainder = 0;
    length = 0;

    if (uppercase == 'X')
        base = "0123456789ABCDEF";
    else
        base = "0123456789abcdef";

    if (number > 15) {
        result = ft_putnbr_hexa((number / 16), uppercase);
        if (result == -1)
            return (-1);
        length += result;
    }
    
    remainder = number % 16;
    if (write(1, &base[remainder], 1) == -1)
        return (-1);

    length += 1;
    return (length);
}

int	ft_putptr(void *ptr)
{
	int	length;
	int	result;

	length = 0;
	result = 0;
	if (ft_putstr("0x") == -1)
		return (-1);
	length += 2;
	result = ft_putnbr_hexa((unsigned long)ptr, 'x');
	if (result == -1)
		return (-1);
	length += result;
	return (len);
}

int	ft_putstr(char *str)
{
	int	length;

	if (!str)
	{
		if (write (1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	length = 0;
	while (*str != '\0')
	{
		if (write(1, str, 1) == -1)
			return (-1);
		length++;
		str++;
	}
	return (length);
}
