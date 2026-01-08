/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalomar <saalomar@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:37:59 by saalomar          #+#    #+#             */
/*   Updated: 2026/01/08 12:48:18 by saalomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	return (node);
}

void	init_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->size = 0;
}

void	build_stack(t_stack *stack, int ac, char **av, int start)
{
	int		i;
	t_node	*node;
	t_node	*tmp;

	i = start;
	while (i < ac)
	{
		node = new_node(ft_atoi(av[i]));
		node->next = NULL;
		if (!stack->top)
			stack->top = node;
		else
		{
			tmp = stack->top;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = node;
		}
		stack->size++;
		i++;
	}
}

void	assign_index(t_stack *stack)
{
	t_node	*i;
	t_node	*j;
	int		index;

	i = stack->top;
	while (i)
	{
		index = 0;
		j = stack->top;
		while (j)
		{
			if (j->value < i->value)
				index++;
			j = j->next;
		}
		i->index = index;
		i = i->next;
	}
}

void	free_stack(t_stack *stack)
{
	t_node	*tmp;

	while (stack->top)
	{
		tmp = stack->top;
		stack->top = stack->top->next;
		free(tmp);
	}
	stack->size = 0;
}
