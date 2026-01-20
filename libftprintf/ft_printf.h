/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalomar <saalomar@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:28:40 by saalomar          #+#    #+#             */
/*   Updated: 2025/12/17 12:37:21 by saalomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int	ft_printf(int fd, const char *format, ...);
int	ft_putchar(char c, int fd);
int	ft_putstr(char *s, int fd);
int	ft_putnbr(int n, int fd);
int	ft_putunsigned(unsigned int n, int fd);
int	ft_puthex(unsigned int n, char type, int fd);
int	ft_putpointer(void *ptr, int fd);
int	ft_printfloat(double n, int fd);
#endif
