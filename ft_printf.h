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

int	ft_putchar(char c);
int ft_putnbr(long number);
int ft_putnbr_hexa(unsigned long number, char uppercase);
int	ft_putptr(void *ptr);
int	ft_putstr(char *str);
int	ft_conversion(const char spec, va_list vargs);
int	ft_printf(char const *format, ...);

#endif
