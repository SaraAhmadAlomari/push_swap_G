/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalomar <saalomar@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:10:50 by saalomar          #+#    #+#             */
/*   Updated: 2025/12/17 12:35:35 by saalomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, char type, int fd)
{
	char	*hexa;
	int		count;

	count = 0;
	if (type == 'X')
		hexa = "0123456789ABCDEF";
	else if (type == 'x')
		hexa = "0123456789abcdef";
	if (n >= 16)
		count += ft_puthex((n / 16), type, fd);
	count += ft_putchar(hexa[n % 16], fd);
	return (count);
}
