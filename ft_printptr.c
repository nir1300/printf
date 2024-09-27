#include "ft_printf.h"

void convert_ptr_hex(unsigned long dec_a)
{
	if (dec_a >= 16)
	{
		convert_ptr_hex(dec_a / 16);
		convert_ptr_hex(dec_a % 16);
	}
	else
	{
		if (dec_a < 10)
			ft_putchar(dec_a + 48);
		else
			ft_putchar(dec_a - 10 + 'a');
	}
}

int	convert_ptr(void *dec)
{
	unsigned long dec_a = (unsigned long) dec;
	int res = ft_putstr("0x");
	convert_ptr_hex(dec_a);
	while (dec_a != 0)
	{
		dec_a /= 16;
		res++;
	}
	return (res);
}