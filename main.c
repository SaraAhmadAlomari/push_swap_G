/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalomar <saalomar@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:40:29 by saalomar          #+#    #+#             */
/*   Updated: 2026/01/18 15:39:35 by saalomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	choose_algorithm(t_stack *a, t_stack *b, t_flags *flags, t_bench *bench)
{
	t_stack	a_original;

	init_stack(&a_original);
	copy_stack(&a_original, a);
	if (is_sorted(a))
		return ;
	else if (flags->complex)
		complex_algorithm(a, b, bench);
	else if (flags->medium)
		medium_algorithm(a, b, bench);
	else if (flags->simple)
		simple_algorithm(a, b, bench);
	else
		adaptive_algorithm(a, b, bench);
	if (flags->bench)
		print_bench(&a_original, bench, flags);
	free_stack(&a_original);
}

int	main(int ac, char **av)
{
	t_flags	flags;
	t_stack	a;
	t_stack	b;
	t_bench	bench;
	int		start;

	if (ac < 2)
		return (0);
	if (!parse_input(ac, av, &flags, &start))
		return (0);
	check_duplicates(ac, av, start);
	init_stack(&a);
	init_stack(&b);
	build_stack(&a, ac, av, start);
	assign_index(&a);
	ft_bzero(&bench, sizeof(t_bench));
	choose_algorithm(&a, &b, &flags, &bench);
	free_stack(&a);
	free_stack(&b);
}
