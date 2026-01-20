/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalomar <saalomar@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 15:34:37 by saalomar          #+#    #+#             */
/*   Updated: 2026/01/18 15:37:35 by saalomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_push_swap.h"

void	copy_stack(t_stack *dest, t_stack *src)
{
	t_node	*curr;
	t_node	*last;
	t_node	*new;

	dest->top = NULL;
	dest->size = 0;
	curr = src->top;
	last = NULL;
	while (curr)
	{
		new = malloc(sizeof(t_node));
		if (!new)
			exit(1);
		new->value = curr->value;
		new->index = curr->index;
		new->next = NULL;
		if (!dest->top)
			dest->top = new;
		else
			last->next = new;
		last = new;
		dest->size++;
		curr = curr->next;
	}
}
