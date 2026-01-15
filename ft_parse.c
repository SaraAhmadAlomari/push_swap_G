/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalomar <saalomar@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:31:08 by saalomar          #+#    #+#             */
/*   Updated: 2026/01/08 11:31:11 by saalomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	check_duplicates(int ac, char **av, int start)
{
	int	i;
	int	j;

	i = start;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				error_exit();
			j++;
		}
		i++;
	}
}

int	parse_input(int ac, char **av, t_flags *f, int *start)
{
	int	i;

	i = 1;
	init_flags(f);
	while (i < ac && is_flag(av[i]))
	{
		if (!handle_flag(av[i], f))
			error_exit();
		i++;
	}
	*start = i;
	if (i >= ac)
		return (0);
	while (i < ac)
	{
		if (!is_valid_int(av[i]))
			error_exit();
		if (ft_atoi(av[i]) > INT_MAX || ft_atoi(av[i]) < INT_MIN)
			error_exit();
		i++;
	}
	return (1);
}
