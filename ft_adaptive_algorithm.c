#include "ft_push_swap.h"

void	adaptive_algorithm(t_stack *a, t_stack *b)
{
	int		n;
	float	disorder;

	disorder = compute_disorder(a);
	n = a->size;
	if (disorder < 0.2)
	{
		if (n <= 5)
			simple_algorithm(a, b);
	}
	else if (disorder >= 0.2 && disorder < 0.5)
	{
		medium_algorithm(a, b);
	}
	else
	{
		complex_algorithm(a, b);
	}
}
