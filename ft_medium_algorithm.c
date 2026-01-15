#include "ft_push_swap.h"

void	medium_algorithm(t_stack *a, t_stack *b)
{
	int	n;
	int	chunk_size;
	int	min;
	int	max;

	n = a->size;
	chunk_size = 1;
	while (chunk_size * chunk_size <= n)
		chunk_size++;
	chunk_size--;
	min = 0;
	while (min < n)
	{
		max = min + chunk_size - 1;
		if (max >= n)
			max = n - 1;
		push_chunk(a, b, min, max);
		min += chunk_size;
	}
	push_back_to_a(a, b);
}
