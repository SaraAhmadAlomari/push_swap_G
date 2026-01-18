/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalomar <saalomar@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:18:20 by saalomar          #+#    #+#             */
/*   Updated: 2025/12/17 12:48:48 by saalomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex_ptr(uintptr_t n)
{
	char	*hexa;
	int		count;

	hexa = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += ft_puthex_ptr(n / 16);
	count += ft_putchar(hexa[n % 16]);
	return (count);
}

int	ft_putpointer(void *ptr)
{
	uintptr_t	address;
	int			count;

	if (!ptr)
		return (write(1, "(nil)", 5));
	count = 2;
	write(1, "0x", 2);
	address = (uintptr_t)ptr;
	count += ft_puthex_ptr(address);
	return (count);
}
