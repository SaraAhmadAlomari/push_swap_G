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

static int	ft_specify_type(char type, va_list args, int fd)
{
	int	count;

	count = 0;
	if (type == 'c')
		count += ft_putchar(va_arg(args, int), fd);
	else if (type == 's')
		count += ft_putstr(va_arg(args, char *), fd);
	else if (type == 'i' || type == 'd')
		count += ft_putnbr(va_arg(args, int), fd);
	else if (type == 'u')
		count += ft_putunsigned(va_arg(args, int), fd);
	else if (type == 'X' || type == 'x')
		count += ft_puthex(va_arg(args, int), type, fd);
	else if (type == 'p')
		count += ft_putpointer(va_arg(args, void *), fd);
	else if (type == '%')
		count += ft_putchar('%', fd);
	else if (type == 'f')
		count += ft_printfloat(va_arg(args, double), fd);
	return (count);
}

int	ft_printf(int fd, const char *format, ...)
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
			count += ft_specify_type(format[++i], args, fd);
		else
			count += ft_putchar(format[i], fd);
		i++;
	}
	va_end(args);
	return (count);
}
