/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalomar <saalomar@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:31:34 by saalomar          #+#    #+#             */
/*   Updated: 2026/01/18 15:38:35 by saalomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "libft/libft.h"
# include "libftprintf/ft_printf.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_flags
{
	int	simple;
	int	medium;
	int	complex;
	int	adaptive;
	int	bench;
}	t_flags;

typedef struct s_node
{
	struct s_node	*next;
	int				value;
	int				index;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

typedef struct s_bench
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_bench;

typedef struct s_range
{
	int	min;
	int	max;
}	t_range;

void	init_flags(t_flags *f);
int		is_flag(char *s);
int		handle_flag(char *s, t_flags *f);
void	error_exit(void);
int		is_valid_int(char *s);
void	check_duplicates(int ac, char **av, int start);
int		parse_input(int ac, char **av, t_flags *f, int *start);
t_node	*new_node(int value);
void	init_stack(t_stack *stack);
void	push_stack_end(t_stack *stack, t_node *node);
void	build_stack(t_stack *stack, int ac, char **av, int start);
void	assign_index(t_stack *stack);
void	free_stack(t_stack *stack);
void	choose_algorithm(t_stack *a, t_stack *b, t_flags *flags,
			t_bench *bench);
void	simple_algorithm(t_stack *a, t_stack *b, t_bench *bench);
void	sort_three(t_stack *a, t_bench *bench);
int		is_sorted(t_stack *stack);
int		find_min(t_stack *a);
int		get_index(t_stack *a, int value);
void	sort_four(t_stack *a, t_stack *b, t_bench *bench);
void	sort_five(t_stack *a, t_stack *b, t_bench *bench);
float	compute_disorder(t_stack *a);
void	adaptive_algorithm(t_stack *a, t_stack *b, t_bench *bench);
void	medium_algorithm(t_stack *a, t_stack *b, t_bench *bench);
void	complex_algorithm(t_stack *a, t_stack *b, t_bench *bench);
void	print_bench(t_stack *a_original, t_bench *bench, t_flags *flags);
int		exists_in_range(t_stack *a, int min, int max);
int		find_max_index(t_stack *s);
int		get_index_position(t_stack *s, int index);
void	push_chunk(t_stack *a, t_stack *b, t_bench *bench, t_range r);
void	push_back_to_a(t_stack *a, t_stack *b, t_bench *bench);
void	sa(t_stack *a, t_bench *bench);
void	sb(t_stack *b, t_bench *bench);
void	ss(t_stack *a, t_stack *b, t_bench *bench);
void	pa(t_stack *a, t_stack *b, t_bench *bench);
void	pb(t_stack *a, t_stack *b, t_bench *bench);
void	ra(t_stack *a, t_bench *bench);
void	rb(t_stack *b, t_bench *bench);
void	rr(t_stack *a, t_stack *b, t_bench *bench);
void	rra(t_stack *a, t_bench *bench);
void	rrb(t_stack *b, t_bench *bench);
void	rrr(t_stack *a, t_stack *b, t_bench *bench);
void	copy_stack(t_stack *dest, t_stack *src);
#endif
