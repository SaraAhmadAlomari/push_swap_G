#include "ft_push_swap.h"

void	complex_algorithm(t_stack *a, t_stack *b)
{
    int total_size;
    int num_chunks;
    int chunk_size;
    int min;
    int max;
    int i;

    total_size = a->size;
    num_chunks = 5;
    chunk_size = total_size / num_chunks;
    min = 0;
    max = chunk_size - 1;
    i = 0;
    while (i < num_chunks)
    {
        push_chunk_to_b(a, b, min, max);
        while (b->size > 0)
        {
            int max_pos;

            max_pos = find_max_position(b);
            if (max_pos <= b->size / 2)
                while (max_pos--)
                    rb(b);
            else
                while (max_pos++ < b->size)
                    rrb(b);
            pa(a, b);
        }
        min += chunk_size;
        max += chunk_size;
        if (i == num_chunks - 2)
            max = total_size - 1;
        i++;
    }
}

