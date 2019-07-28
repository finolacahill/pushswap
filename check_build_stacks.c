/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 15:01:00 by fcahill           #+#    #+#             */
/*   Updated: 2019/07/10 15:01:04 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		*ft_intarraycpy(int *source, int *dest, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		dest[i] = source[i];
		++i;
	}
	return (dest);
}

int		ft_buildstacks(t_stacks *stack, char **args)
{
	if (!(stack->a = (int *)malloc(sizeof(int) * stack->a_count)))
		return (0);
	if (!(stack->b = (int *)malloc(sizeof(int) * stack->a_count)))
		return (0);
	if (!(stack->c = (int *)malloc(sizeof(int) * stack->a_count)))
		return (0);
	if (!(ft_create_stacks(stack->a, stack->b, args)))
		return (0);
	stack->c = ft_intarraycpy(stack->a, stack->c, stack->a_count);
	ft_perf_quicksort(stack->c, 0, stack->a_count);
	return (1);
}

int		ft_count_numbers(char **arg, int limit)
{
	int	i;
	int	count;
	int new;

	count = 0;
	new = 0;
	i = 0;
	while (i < limit)
	{
		if ((new = ft_is_single_arg(arg[i])) < 0)
			return (new);
		count = count + new;
		if (count < 0)
			return (count);
		++i;
	}
	return (count);
}

int		is_sorted(int *a, int count_a)
{
	while (--count_a > 0)
	{
		if (a[count_a] < a[count_a - 1])
			return (0);
	}
	return (1);
}

int		there_are_duplicates(int *a, int quantity_args)
{
	int	i;
	int	j;

	i = 0;
	while (i < quantity_args)
	{
		j = 0;
		while (j < quantity_args)
		{
			if (i != j && a[i] == a[j])
				return (1);
			++j;
		}
		++i;
	}
	return (0);
}
