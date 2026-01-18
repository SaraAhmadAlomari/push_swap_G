/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bench.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalomar <saalomar@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 12:43:58 by saalomar          #+#    #+#             */
/*   Updated: 2026/01/18 15:40:23 by saalomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int bench_total_ops(t_bench *bench)
{
    return (
        bench->sa + bench->sb + bench->ss +
        bench->pa + bench->pb +
        bench->ra + bench->rb + bench->rr +
        bench->rra + bench->rrb + bench->rrr
    );
}

const char *bench_strategy(t_stack *a, t_flags *flags)
{
    float disorder;

    if (flags->simple)
        return "Simple / O(n²)";
    if (flags->medium)
        return "Medium / O(n√n)";
    if (flags->complex)
        return "Complex / O(n log n)";

    disorder = compute_disorder(a) * 100;

    if (disorder < 20.0)
        return "Tiny / O(n²)";
    else if (disorder <= 50.0)
        return "Chunk / O(n√n)";
    else
        return "Mostly sorted / O(n log n)";
}
void print_bench(t_stack *a_original, t_bench *bench, t_flags *flags)
{
    float disorder = compute_disorder(a_original) * 100;

    printf("[bench] disorder: %.2f%%\n", disorder);
   ft_printf("[bench] strategy: %s\n", bench_strategy(a_original, flags));
    ft_printf("[bench] total_ops: %d\n",
        bench->sa + bench->sb + bench->ss +
        bench->pa + bench->pb +
        bench->ra + bench->rb + bench->rr +
        bench->rra + bench->rrb + bench->rrr);
    ft_printf("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n",
        bench->sa, bench->sb, bench->ss,
        bench->pa, bench->pb);
    ft_printf("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
        bench->ra, bench->rb, bench->rr,
        bench->rra, bench->rrb, bench->rrr);
}

