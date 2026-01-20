/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalomar <saalomar@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:08:33 by saalomar          #+#    #+#             */
/*   Updated: 2026/01/18 13:35:40 by saalomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	rotate_stack(t_stack *s)
{
	t_node	*first;
	t_node	*last;

	if (!s || s->size < 2)
		return ;
	first = s->top;
	s->top = first->next;
	first->next = NULL;
	last = s->top;
	while (last->next)
		last = last->next;
	last->next = first;
}

void	ra(t_stack *a, t_bench *bench)
{
	rotate_stack(a);
	write(1, "ra\n", 3);
	if (bench)
		bench->ra++;
}

void	rb(t_stack *b, t_bench *bench)
{
	rotate_stack(b);
	write(1, "rb\n", 3);
	if (bench)
		bench->rb++;
}

void	rr(t_stack *a, t_stack *b, t_bench *bench)
{
	rotate_stack(a);
	rotate_stack(b);
	write(1, "rr\n", 3);
	if (bench)
		bench->rr++;
}
