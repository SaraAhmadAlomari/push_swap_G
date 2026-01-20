/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex_algorithm.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalomar <saalomar@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 11:19:48 by saalomar          #+#    #+#             */
/*   Updated: 2026/01/18 14:02:29 by saalomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_push_swap.h"

static int	get_max_bits(int size)
{
	int	max_bits;
	int	max_num;

	max_num = size - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	complex_algorithm(t_stack *a, t_stack *b, t_bench *bench)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	max_bits = get_max_bits(a->size);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		size = a->size;
		while (j++ < size)
		{
			if (((a->top->index >> i) & 1) == 1)
				ra(a, bench);
			else
				pb(a, b, bench);
		}
		while (b->size > 0)
			pa(a, b, bench);
		i++;
	}
}
