/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalomar <saalomar@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 10:34:48 by saalomar          #+#    #+#             */
/*   Updated: 2026/01/18 10:34:52 by saalomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_node	*cur;

	cur = stack->top;
	while (cur && cur->next)
	{
		if (cur->value > cur->next->value)
			return (0);
		cur = cur->next;
	}
	return (1);
}

int	find_min(t_stack *a)
{
	int		min;
	t_node	*tmp;

	tmp = a->top;
	min = tmp->value;
	while (tmp)
	{
		if (min > tmp->value)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}

int	get_index(t_stack *a, int value)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = a->top;
	while (tmp)
	{
		if (tmp->value == value)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (-1);
}

float	compute_disorder(t_stack *a)
{
	int		mistakes;
	int		total_pairs;
	t_node	*i;
	t_node	*j;

	mistakes = 0;
	total_pairs = 0;
	i = a->top;
	while (i)
	{
		j = i->next;
		while (j)
		{
			total_pairs++;
			if (i->value > j->value)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	if (total_pairs == 0)
		return (0);
	return ((float)mistakes / (float)total_pairs);
}
