/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalomar <saalomar@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:10:21 by saalomar          #+#    #+#             */
/*   Updated: 2026/01/18 13:35:14 by saalomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	reverse_rotate_stack(t_stack *s)
{
	t_node	*prev;
	t_node	*last;

	if (!s || s->size < 2)
		return ;
	prev = NULL;
	last = s->top;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = s->top;
	s->top = last;
}

void	rra(t_stack *a, t_bench *bench)
{
	reverse_rotate_stack(a);
	write(1, "rra\n", 4);
	if (bench)
		bench->rra++;
}

void	rrb(t_stack *b, t_bench *bench)
{
	reverse_rotate_stack(b);
	write(1, "rrb\n", 4);
	if (bench)
		bench->rrb++;
}

void	rrr(t_stack *a, t_stack *b, t_bench *bench)
{
	reverse_rotate_stack(a);
	reverse_rotate_stack(b);
	write(1, "rrr\n", 4);
	if (bench)
		bench->rrr++;
}
