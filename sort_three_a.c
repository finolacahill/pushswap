/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 16:52:34 by fcahill           #+#    #+#             */
/*   Updated: 2019/07/10 16:52:36 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	first_is_smallest(t_stacks *stack, t_list **instructions)
{
	if (ft_move_and_save("ra", stack, instructions) == 0)
		return (0);
	if (ft_sort_two(stack, instructions) == 0)
		return (0);
	if (ft_move_and_save("rra", stack, instructions) == 0)
		return (0);
	return (1);
}

static int	second_is_smallest(t_stacks *stack, t_list **instructions)
{
	if (stack->a_count == 3)
	{
		if (is_largest(stack->a, 3, 0))
			if (ft_move_and_save("ra", stack, instructions) == 0)
				return (0);
		if ((is_largest(stack->a, 3, 2)))
			if (ft_sort_two(stack, instructions) == 0)
				return (0);
	}
	else
	{
		if (ft_sort_two(stack, instructions) == 0)
			return (0);
		if (is_sorted(stack->a, 3) == 0)
		{
			if (ft_move_and_save("pb", stack, instructions) == 0)
				return (0);
			if (ft_sort_two(stack, instructions) == 0)
				return (0);
			if (ft_move_and_save("pa", stack, instructions) == 0)
				return (0);
		}
	}
	return (1);
}

static int	third_is_smallest(t_stacks *stack, t_list **instructions)
{
	if ((is_largest(stack->a, 3, 1)) && stack->a_count == 3)
		if (ft_move_and_save("rra", stack, instructions) == 0)
			return (0);
	if ((is_largest(stack->a, 3, 0)) && stack->a_count == 3)
	{
		if (ft_sort_two(stack, instructions) == 0)
			return (0);
		if (ft_move_and_save("rra", stack, instructions) == 0)
			return (0);
	}
	else
	{
		if (ft_sort_two(stack, instructions) == 0)
			return (0);
		if (ft_move_and_save("pb", stack, instructions) == 0)
			return (0);
		if (ft_sort_two(stack, instructions) == 0)
			return (0);
		if (ft_move_and_save("pa", stack, instructions) == 0)
			return (0);
		if (ft_sort_two(stack, instructions) == 0)
			return (0);
	}
	return (1);
}

int			ft_sort_three_a(t_stacks *stack, t_list **instructions)
{
	if ((is_smallest(stack->a, 3, 0)) && (is_largest(stack->a, 3, 1)))
	{
		if (first_is_smallest(stack, instructions) == 0)
			return (0);
	}
	if ((is_smallest(stack->a, 3, 1)))
	{
		if (second_is_smallest(stack, instructions) == 0)
			return (0);
	}
	if (is_smallest(stack->a, 3, 2))
	{
		if (third_is_smallest(stack, instructions) == 0)
			return (0);
	}
	return (1);
}
