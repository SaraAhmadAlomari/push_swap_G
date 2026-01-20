/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalomar <saalomar@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:41:42 by saalomar          #+#    #+#             */
/*   Updated: 2026/01/18 13:34:14 by saalomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	swap_stack(t_stack *s)
{
	t_node	*first;
	t_node	*second;

	if (!s || s->size < 2)
		return ;
	first = s->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	s->top = second;
}

void	sa(t_stack *a, t_bench *bench)
{
	swap_stack(a);
	write(1, "sa\n", 3);
	if (bench)
		bench->sa++;
}

void	sb(t_stack *b, t_bench *bench)
{
	swap_stack(b);
	write(1, "sb\n", 3);
	if (bench)
		bench->sb++;
}

void	ss(t_stack *a, t_stack *b, t_bench *bench)
{
	swap_stack(a);
	swap_stack(b);
	write(1, "ss\n", 3);
	if (bench)
		bench->ss++;
}
