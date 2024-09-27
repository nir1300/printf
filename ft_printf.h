/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrumpfhu <nrumpfhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:01:50 by nrumpfhu          #+#    #+#             */
/*   Updated: 2024/09/27 15:39:38 by nrumpfhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_putchar(int c);
int	ft_printf(const char *format, ...);
int	ft_printformat(const char format, va_list args);
int	ft_putstr(char *str);
int	ft_countnum_uns(unsigned int n);
int ft_countnum(int n);
int	ft_putnbr_uns(unsigned int n);
int	ft_putnbr(int n, const char format);
int	convert_dec_hex(unsigned int dec, const char format);
int puthex(unsigned int dec);
void convert_ptr_hex(unsigned long dec_a);
int	convert_ptr(void *deco);
