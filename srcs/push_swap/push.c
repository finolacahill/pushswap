/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 19:07:26 by fcahill           #+#    #+#             */
/*   Updated: 2019/07/10 19:07:28 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pushswap.h"

static int	ft_first_split(int block_a, t_stacks *stack, t_list **instructions)
{
	int	median;
	int	medianb;
	int	block_b;

	block_b = 0;
	median = find_median(stack->a, block_a);
	while (--block_a >= 0)
	{
		if (stack->a[0] <= median)
		{
			if (ft_move_and_save("pb\0", stack, instructions) == 0)
				return (0);
		}
		else
		{
			if (ft_move_and_save("ra", stack, instructions) == 0)
				return (0);
		}
		if (is_split('a', block_a + 1, median, stack) == 1)
			return (1);
	}
	return (1);
}

int			ft_split_block_a(int block_a, t_stacks *s, t_list **instruc)
{
	int	median;
	int	flag;
	int	block_b;

	block_b = 0;
	flag = 0;
	median = find_median(s->a, block_a);
	if (block_a == s->a_count)
		flag = 1;
	while (block_a-- != 0)
	{
		if (s->a[0] <= median)
		{
			if (ft_move_and_save("pb\0", s, instruc) == 0)
				return (0);
		}
		else
		{
			if (ft_move_and_save("ra", s, instruc) == 0)
				return (0);
		}
		if (flag == 1 && is_split('a', block_a + 1, median, s) == 1)
			return (1);
	}
	return (1);
}

int			ft_split_block_b(int block_b, t_stacks *s, t_list **instruc)
{
	int	median;
	int	block_a;
	int	flag;

	flag = 0;
	block_a = 0;
	if (block_b == s->b_count)
		flag = 1;
	median = find_median(s->b, block_b);
	while (block_b-- != 0)
	{
		if (s->b[0] >= median)
		{
			if (ft_move_and_save("pa", s, instruc) == 0)
				return (0);
		}
		else
		{
			if (ft_move_and_save("rb", s, instruc) == 0)
				return (0);
		}
		if (flag == 1 && is_split('b', block_b + 1, median, s) == 1)
			return (1);
	}
	return (1);
}

static int	ft_push_to_a(int block_b, t_stacks *stack, t_list **instructions)
{
	int	old_a;

	old_a = stack->a_count;
	if (ft_sort_block_b(block_b, stack, instructions) == 0)
		return (0);
	if (stack->a_count != old_a + block_b)
	{
		block_b = block_b - (stack->a_count - old_a);
		if (ft_push_to_a(block_b, stack, instructions) == 0)
			return (0);
	}
	return (1);
}

int			ft_push_to_b(t_stacks *stack, t_list **instructions)
{
	int	median;
	int	block_a;
	int	old_block_b;

	block_a = stack->a_count;
	old_block_b = stack->b_count;
	if (stack->a_count <= 4)
	{
		if (ft_sort_to_four(stack, instructions, stack->a_count) == 0)
			return (0);
		return (1);
	}
	if (ft_first_split(block_a, stack, instructions) == 0)
		return (0);
	if (stack->a_count > 0)
	{
		if (ft_push_to_b(stack, instructions) == 0)
			return (0);
	}
	if (ft_push_to_a(stack->b_count - old_block_b, stack, instructions) == 0)
		return (0);
	return (1);
}
