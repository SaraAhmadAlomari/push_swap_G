#include "ft_printf.h"

int	ft_printfloat(double n, int fd)
{
	int		count;
	long	int_part;
	long	frac;

	count = 0;
	if (n < 0)
	{
		count += ft_putchar('-', fd);
		n = -n;
	}
	int_part = (long)n;
	frac = (long)((n - int_part) * 100 + 0.5);
	if (frac == 100)
	{
		int_part += 1;
		frac = 0;
	}
	count += ft_putnbr(int_part, fd);
	count += ft_putchar('.', fd);
	if (frac < 10)
		count += ft_putchar('0', fd);
	count += ft_putnbr(frac, fd);
	return (count);
}
