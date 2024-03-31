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

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		i += ft_putstr("(null)");
		return (i);
	}
	while (*str != '\0')
	{
		i += ft_putchar(*str);
		str++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int	a;

	a = 0;
	if (n == -2147483648)
	{
		a += ft_putchar('-');
		a += ft_putchar('2');
		n = 147483648;
	}
	if (n < 0)
	{
		a += ft_putchar('-');
		n = -n;
	}
	while (n >= 10)
	{
		a += ft_putnbr(n / 10);
		n %= 10;
	}
	a += ft_putchar(n + 48);
	return (a);
}

int	ft_putnbr_u(unsigned int n)
{
	int	i;

	i = 0;
	if (n > 9)
	{
		i += ft_putnbr(n / 10);
		i += ft_putnbr(n % 10);
	}
	else
	{
		i += ft_putchar(n + 48);
	}
	return (i);
}
