/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 18:12:36 by fcahill           #+#    #+#             */
/*   Updated: 2019/07/10 18:12:38 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pushswap.h"

static int	sort_third(t_stacks *stack, t_list **instructions)
{
	if (ft_move_and_save("ra", stack, instructions) == 0)
		return (0);
	if (ft_sort_two(stack, instructions) == 0)
		return (0);
	if (ft_move_and_save("rra", stack, instructions) == 0)
		return (0);
	if (ft_sort_two(stack, instructions) == 0)
		return (0);
	return (1);
}

static int	sort_fourth(t_stacks *stack, t_list **instructions)
{
	if (stack->a[3] < stack->a[1])
	{
		if (ft_move_and_save("rra", stack, instructions) == 0)
			return (0);
		if (ft_sort_two(stack, instructions) == 0)
			return (0);
		return (1);
	}
	if (ft_move_and_save("rra", stack, instructions) == 0)
		return (0);
	if (ft_move_and_save("rra", stack, instructions) == 0)
		return (0);
	if (ft_sort_two(stack, instructions) == 0)
		return (0);
	if (ft_move_and_save("ra", stack, instructions) == 0)
		return (0);
	if (ft_move_and_save("ra", stack, instructions) == 0)
		return (0);
	return (1);
}

static int	ft_sort_four(t_stacks *stack, t_list **instructions)
{
	while (is_sorted(stack->a, 4) == 0)
	{
		if ((is_smallest(stack->a, 4, 3) == 1))
			if (ft_move_and_save("rra", stack, instructions) == 0)
				return (0);
		if (is_largest(stack->a, 4, 0) == 1)
			if (ft_move_and_save("ra", stack, instructions) == 0)
				return (0);
		if (ft_sort_two(stack, instructions) == 0)
			return (0);
		if (stack->a[2] < stack->a[1])
		{
			if (sort_third(stack, instructions) == 0)
				return (0);
		}
		if (stack->a[3] < stack->a[2])
		{
			if (sort_fourth(stack, instructions) == 0)
				return (0);
		}
	}
	return (1);
}

int			ft_sort_to_four(t_stacks *s, t_list **instruc, int block)
{
	if (block == 2)
		if (ft_sort_two(s, instruc) == 0)
			return (0);
	if (block == 3)
		if (ft_sort_three_a(s, instruc) == 0)
			return (0);
	if (block == 4)
		if (ft_sort_four(s, instruc) == 0)
			return (0);
	return (1);
}
