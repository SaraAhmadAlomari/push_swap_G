/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_medium_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalomar <saalomar@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 10:34:25 by saalomar          #+#    #+#             */
/*   Updated: 2026/01/18 14:02:11 by saalomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_push_swap.h"

void	medium_algorithm(t_stack *a, t_stack *b, t_bench *bench)
{
	int			n;
	int			chunk_size;
	t_range		r;

	n = a->size;
	chunk_size = 1;
	while (chunk_size * chunk_size <= n)
		chunk_size++;
	chunk_size--;
	r.min = 0;
	while (r.min < n)
	{
		r.max = r.min + chunk_size - 1;
		if (r.max >= n)
			r.max = n - 1;
		push_chunk(a, b, bench, r);
		r.min += chunk_size;
	}
	push_back_to_a(a, b, bench);
}
