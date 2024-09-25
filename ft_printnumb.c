/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnumb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrumpfhu <nrumpfhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:01:48 by nrumpfhu          #+#    #+#             */
/*   Updated: 2024/09/25 16:20:01 by nrumpfhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putnbr_uns(unsigned int n)
{
	int	count;

	count = 0;
	if ((int)n < 0 && count == 0)
		n = 4294967295 + (int)n + 1;
	if (n > 9)
	{
		ft_putnbr_uns(n / 10);
		n = n % 10;
	}
	if (n >= 0 && n <= 9)
	{
		ft_putchar(n + '0');
		count++;
	}
	return (count);
}

int	ft_putnbr(int n, const char format)
{
	int	count;

	count = 0;
	if (n < 0 && format != 'u')
	{
		ft_putchar('-');
		if (n == -2147483648)
		{
			write(1, "2", 1);
			count++;
			n = -147483648;
		}
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10, format);
		count++;
		n = n % 10;
	}
	if (n >= 0 && n <= 9)
		ft_putchar(n + '0');
	return (count + 1);
}
