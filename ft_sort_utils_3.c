#include "ft_push_swap.h"

int	find_max_position(t_stack *b)
{
	int		pos;
	int		max_pos;
	int		max_index;
	t_node	*tmp;

	pos = 0;
	max_index = -1;
	max_pos = 0;
	tmp = b->top;
	while (tmp)
	{
		if (tmp->index > max_index)
		{
			max_index = tmp->index;
			max_pos = pos;
		}
		pos++;
		tmp = tmp->next;
	}
	return (max_pos);
}

void	push_chunk_to_b(t_stack *a, t_stack *b, int min, int max)
{
	int	i;
	int	size;

	i = 0;
	size = a->size;
	while (i < size)
	{
		if (a->top->index >= min && a->top->index <= max)
		{
			pb(a, b);
			if (b->top->index < (min + max) / 2)
				rb(b);
		}
		else
			ra(a);
		i++;
	}
}
