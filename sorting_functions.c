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

#include "pushswap.h"

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

void	ft_perf_quicksort(int *array, int first, int last)
{
	int i;
	int j;
	int pivot;

	if (first < last)
	{
		pivot = first;
		i = first;
		j = last - 1;
		while (i < j)
		{
			while (array[i] <= array[pivot] && i < last - 1)
				i++;
			while (array[j] > array[pivot])
				j--;
			if (i < j)
				ft_swap(&array[i], &array[j]);
		}
		ft_swap(&array[pivot], &array[j]);
		ft_perf_quicksort(array, first, j);
		ft_perf_quicksort(array, j + 1, last);
	}
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
