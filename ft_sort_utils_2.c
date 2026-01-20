/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalomar <saalomar@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 10:34:56 by saalomar          #+#    #+#             */
/*   Updated: 2026/01/18 13:59:40 by saalomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_push_swap.h"

int	exists_in_range(t_stack *a, int min, int max)
{
	t_node	*tmp;

	tmp = a->top;
	while (tmp)
	{
		if (tmp->index >= min && tmp->index <= max)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	find_max_index(t_stack *s)
{
	int		max;
	t_node	*tmp;

	tmp = s->top;
	max = tmp->index;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	return (max);
}

int	get_index_position(t_stack *s, int index)
{
	int		pos;
	t_node	*tmp;

	tmp = s->top;
	pos = 0;
	while (tmp)
	{
		if (tmp->index == index)
			return (pos);
		pos++;
		tmp = tmp->next;
	}
	return (-1);
}

void	push_chunk(t_stack *a, t_stack *b, t_bench *bench, t_range r)
{
	while (exists_in_range(a, r.min, r.max))
	{
		if (a->top->index >= r.min && a->top->index <= r.max)
		{
			pb(a, b, bench);
			if (b->top->index < (r.min + r.max) / 2)
				rb(b, bench);
		}
		else
			ra(a, bench);
	}
}

void	push_back_to_a(t_stack *a, t_stack *b, t_bench *bench)
{
	int	max;
	int	pos;

	while (b->size > 0)
	{
		max = find_max_index(b);
		pos = get_index_position(b, max);
		if (pos <= b->size / 2)
		{
			while (b->top->index != max)
				rb(b, bench);
		}
		else
		{
			while (b->top->index != max)
				rrb(b, bench);
		}
		pa(a, b, bench);
	}
}
