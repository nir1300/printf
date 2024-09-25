/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrumpfhu <nrumpfhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:01:54 by nrumpfhu          #+#    #+#             */
/*   Updated: 2024/09/25 16:18:12 by nrumpfhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/*
void	ptrhex(void *ptr)
{
	int		remainder;
	char	*hex;
	int		i;

	hex = malloc(9);
	if (!hex)
		return (NULL);
	*hex = '\0';
	hex++;
	i = 0;
	while (ptr != NULL)
	{
		*hex = ptr[i] + 55;
		hex++;
		i++;
	}
	return (hex);
}
*/

int	ft_countoutput(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// else if (*format == 'p')
//  ret += ptrhex(va_arg(args, void*));

int	ft_printformat(const char format, va_list args)
{
	int	ret;

	ret = 0;
	if (format == '%')
		ret += ft_putchar('%');
	else if (format == 'c')
		ret += ft_putchar(va_arg(args, int));
	else if (format == 's')
		ret += ft_putstr(va_arg(args, char *));
	else if (format == 'i' || format == 'd')
		ret += ft_putnbr(va_arg(args, int), format);
	else if (format == 'u')
		ret += ft_putnbr_uns(va_arg(args, unsigned int));
	else if (format == 'X' || format == 'x')
		ret += ft_puthex(convert_dec_hex(va_arg(args, int), format));
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		ret;

	ret = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *format != '\0')
		{
			format++;
			ret += ft_printformat(*format, args);
		}
		else
			ret += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (ret);
}


int	main(void)
{
	char			c;
	char			*s;
	int				i;
	void			*ptr;
	int				dec;
	unsigned int	unint;
	int				a;
	int				d;
	int				x;
	int				q;
	int				b;
	int				e;
	int				y;
	int				p;

	c = 'h';
	s = "hello";
	i = 012;
	ptr = &i;
	dec = 012;
	unint = -234;
	a = printf("c: %c, ", c);
	printf("len c: %d\n", a);
	d = printf("s: %s, ", s);
	printf("len s: %d\n", d);
	printf("p: %p\n", ptr);
	printf("d: %d\n", dec);
	printf("i: %i\n", i);
	int u = printf("u: %u, ", unint);
	printf("len u: %d\n", u);
	x = printf("x: %x, ", i);
	printf("len x: %d\n", x);
	printf("X: %X\n", i);
	q = printf("Percent: %%\n");
	printf("len percent: %d\n", q);
	//printf("%"); 
	// not sure how to correctly implement this case,
	// return null in my function?
	printf("\n");
	b = ft_printf("c: %c, ", c);
	printf("len c: %d\n", b);
	e = ft_printf("s: %s, ", s);
	ft_printf("len s: %d\n", e);
	// ft_printf("p: %p\n", ptr);
	ft_printf("d: %d\n", dec);
	ft_printf("i: %i\n", i);
	int uu = ft_printf("u: %u, ", unint);
	ft_printf("len u: %d\n", uu); //dis wrong
	y = ft_printf("x: %x, ", i);
	ft_printf("len x: %d\n", y);
	ft_printf("X: %X\n", i);
	p = ft_printf("Percent: %%\n");
	ft_printf("len percent: %d\n", p);
	//ft_printf("%%");
}