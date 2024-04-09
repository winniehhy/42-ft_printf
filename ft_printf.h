/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:53:45 by hheng             #+#    #+#             */
/*   Updated: 2024/04/09 18:48:21 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

# include <stdio.h>

int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_putnbr(int n);
int	ft_putnbr_u(unsigned int n);
int	printf_hex_l(unsigned long long n);
int	printf_hex_u(unsigned long long n);
int	printf_pointer(unsigned long long p);
int	printf_specifiers(va_list args, char format, int a);
int	ft_printf(const char *format, ...);

#endif
