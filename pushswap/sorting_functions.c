/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 19:27:27 by fcahill           #+#    #+#             */
/*   Updated: 2019/07/10 19:27:30 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int		ft_push_n_to_name(t_stacks *s, int n, char name, t_list **instructions)
{
	int i;

	i = 0;
	while (i < n)
	{
		if (name == 'a')
			if (ft_move_and_save("pa", s, instructions) == 0)
				return (0);
		if (name == 'b')
			if (ft_move_and_save("pb", s, instructions) == 0)
				return (0);
		++i;
	}
	return (1);
}

int		find_median(int *stack, int len)
{
	int	cpy[len];
	int	med;
	int	i;

	i = 0;
	med = 0;
	if (len > 1)
	{
		ft_intarraycpy(stack, cpy, len);
		ft_perf_quicksort(cpy, 0, len);
		--len;
		med = cpy[len / 2];
	}
	return (med);
}

int		is_largest(int *stack, int block, int placement)
{
	int	i;

	i = 0;
	while (i < block)
	{
		if (stack[i] > stack[placement])
			return (0);
		++i;
	}
	return (1);
}

int		is_smallest(int *stack, int block, int placement)
{
	int	i;

	i = 0;
	while (i < block)
	{
		if (stack[i] < stack[placement])
			return (0);
		++i;
	}
	return (1);
}
