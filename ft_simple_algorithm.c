/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalomar <saalomar@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:32:07 by saalomar          #+#    #+#             */
/*   Updated: 2026/01/08 14:04:12 by saalomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_push_swap.h"

void	simple_algorithm(t_stack *a, t_stack *b)
{
	(void)b;
	if (a->size == 2)
	{
		if (a->top->index > a->top->next->index)
			sa(a);
	}
	else if (a->size == 3)
		sort_three(a);
	else if (a->size == 4)
		sort_four(a, b);
	else if (a->size == 5)
		sort_five(a, b);
}

void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->top->index;
	second = a->top->next->index;
	third = a->top->next->next->index;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

void	sort_four(t_stack *a, t_stack *b)
{
	int	min;

	min = find_min(a);
	if (is_sorted(a))
		return ;
	while (a->top->value != min)
	{
		if (get_index(a, min) <= a->size / 2)
			ra(a);
		else
			rra(a);
	}
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	min1;

	if (is_sorted(a))
		return ;
	min1 = find_min(a);
	while (a->top->value != min1)
	{
		if (get_index(a, min1) <= a->size / 2)
			ra(a);
		else
			rra(a);
	}
	pb(a, b);
	sort_four(a, b);
	pa(a, b);
}
