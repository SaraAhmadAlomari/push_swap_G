/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalomar <saalomar@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 10:59:01 by saalomar          #+#    #+#             */
/*   Updated: 2025/12/17 13:04:26 by saalomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_specify_type(char type, va_list args)
{
	int	count;

	count = 0;
	if (type == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (type == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (type == 'i' || type == 'd')
		count += ft_putnbr(va_arg(args, int));
	else if (type == 'u')
		count += ft_putunsigned(va_arg(args, int));
	else if (type == 'X' || type == 'x')
		count += ft_puthex(va_arg(args, int), type);
	else if (type == 'p')
		count += ft_putpointer(va_arg(args, void *));
	else if (type == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	int		i;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
			count += ft_specify_type(format[++i], args);
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
