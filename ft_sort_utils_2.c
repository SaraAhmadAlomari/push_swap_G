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

void	push_chunk(t_stack *a, t_stack *b, int min, int max)
{
	while (exists_in_range(a, min, max))
	{
		if (a->top->index >= min && a->top->index <= max)
		{
			pb(a, b);
			if (b->top->index < (min + max) / 2)
				rb(b);
		}
		else
			ra(a);
	}
}

void	push_back_to_a(t_stack *a, t_stack *b)
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
				rb(b);
		}
		else
		{
			while (b->top->index != max)
				rrb(b);
		}
		pa(a, b);
	}
}
