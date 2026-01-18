/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalomar <saalomar@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:32:07 by saalomar          #+#    #+#             */
/*   Updated: 2026/01/18 13:57:10 by saalomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_push_swap.h"

void	simple_algorithm(t_stack *a, t_stack *b, t_bench *bench)
{
	(void)b;
	if (a->size == 2)
	{
		if (a->top->index > a->top->next->index)
			sa(a, bench);
	}
	else if (a->size == 3)
		sort_three(a, bench);
	else if (a->size == 4)
		sort_four(a, b, bench);
	else if (a->size == 5)
		sort_five(a, b, bench);
}

void	sort_three(t_stack *a, t_bench *bench)
{
	int	first;
	int	second;
	int	third;

	first = a->top->index;
	second = a->top->next->index;
	third = a->top->next->next->index;
	if (first > second && second < third && first < third)
		sa(a, bench);
	else if (first > second && second > third)
	{
		sa(a, bench);
		rra(a, bench);
	}
	else if (first > second && second < third && first > third)
		ra(a, bench);
	else if (first < second && second > third && first < third)
	{
		sa(a, bench);
		ra(a, bench);
	}
	else if (first < second && second > third && first > third)
		rra(a, bench);
}

void	sort_four(t_stack *a, t_stack *b, t_bench *bench)
{
	int	min;

	min = find_min(a);
	if (is_sorted(a))
		return ;
	while (a->top->value != min)
	{
		if (get_index(a, min) <= a->size / 2)
			ra(a, bench);
		else
			rra(a, bench);
	}
	pb(a, b, bench);
	sort_three(a, bench);
	pa(a, b, bench);
}

void	sort_five(t_stack *a, t_stack *b, t_bench *bench)
{
	int	min1;

	if (is_sorted(a))
		return ;
	min1 = find_min(a);
	while (a->top->value != min1)
	{
		if (get_index(a, min1) <= a->size / 2)
			ra(a, bench);
		else
			rra(a, bench);
	}
	pb(a, b, bench);
	sort_four(a, b, bench);
	pa(a, b, bench);
}
