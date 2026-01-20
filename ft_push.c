/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalomar <saalomar@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:06:55 by saalomar          #+#    #+#             */
/*   Updated: 2026/01/18 13:34:47 by saalomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	push_stacks(t_stack *from, t_stack *to)
{
	t_node	*tmp;

	if (!from || from->size == 0)
		return ;
	tmp = from->top;
	from->top = tmp->next;
	from->size--;
	tmp->next = to->top;
	to->top = tmp;
	to->size++;
}

void	pa(t_stack *a, t_stack *b, t_bench *bench)
{
	push_stacks(b, a);
	write(1, "pa\n", 3);
	if (bench)
		bench->pa++;
}

void	pb(t_stack *a, t_stack *b, t_bench *bench)
{
	push_stacks(a, b);
	write(1, "pb\n", 3);
	if (bench)
		bench->pb++;
}
