/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrumpfhu <nrumpfhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:01:45 by nrumpfhu          #+#    #+#             */
/*   Updated: 2024/09/25 16:03:08 by nrumpfhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_puthex(char *str)
{
	int	n;
	int	count;

	count = 0;
	n = 0;
	while (str[--n] != 0)
	{
		write(1, &str[n], 1);
		count++;
	}
	return (count);
}

// malloc not correct size yet, not sure how

char	*convert_dec_hex(int dec, const char format)
{
	int		remainder;
	char	*hex;

	hex = malloc(9);
	if (!hex)
		return (NULL);
	*hex = '\0';
	hex++;
	while (dec > 0)
	{
		remainder = dec % 16;
		if (remainder < 10)
			*hex = remainder + 48;
		else if (format == 'x')
			*hex = remainder - 10 + 'a';
		else if (format == 'X')
			*hex = remainder - 10 + 'A';
		dec /= 16;
		hex++;
	}
	return (hex);
}
