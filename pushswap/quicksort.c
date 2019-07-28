/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 19:37:44 by fcahill           #+#    #+#             */
/*   Updated: 2019/07/10 19:37:48 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int		is_split(char name, int block, int median, t_stacks *stack)
{
	int i;

	i = 0;
	if (name == 'a')
	{
		while (i < block)
		{
			if (stack->a[i] <= median)
				return (0);
			++i;
		}
	}
	if (name == 'b')
	{
		while (i < block)
		{
			if (stack->b[i] >= median)
				return (0);
			++i;
		}
	}
	return (1);
}

int		ft_smart_rotate_a(int block, t_stacks *st, t_list **instruc)
{
	int a;
	int b;
	int median;

	a = block;
	b = st->b_count;
	median = find_median(&st->a[st->a_count - block], block);
	if (block == st->a_count)
		return (1);
	while (block-- != 0)
	{
		if (ft_move_and_save("rra", st, instruc) == 0)
			return (0);
		if (st->a[0] <= median)
		{
			if (ft_move_and_save("pb", st, instruc) == 0)
				return (0);
		}
	}
	if (is_sorted(st->a, (a - (st->b_count - b))) == 0)
		if (ft_sort_block_a((a - (st->b_count - b)), st, instruc) == 0)
			return (0);
	if (ft_sort_block_b((st->b_count - b), st, instruc) == 0)
		return (0);
	return (1);
}

int		ft_smart_rotate_b(int block, t_stacks *st, t_list **instruc)
{
	int a;
	int b;
	int median;

	b = block;
	a = st->a_count;
	median = find_median(&st->b[st->b_count - block], block);
	if (block == st->b_count)
		return (1);
	while (block-- != 0)
	{
		if (ft_move_and_save("rrb", st, instruc) == 0)
			return (0);
		if (st->b[0] >= median)
			if (ft_move_and_save("pa", st, instruc) == 0)
				return (0);
	}
	if (st->a_count - a > 1)
		if (ft_sort_block_a(st->a_count - a, st, instruc) == 0)
			return (0);
	if ((b - (st->a_count - a)) > 0)
		if (ft_sort_block_b(b - (st->a_count - a), st, instruc) == 0)
			return (0);
	return (1);
}

int		ft_sort_block_b(int block_b, t_stacks *stack, t_list **instructions)
{
	int	block_a;
	int	old_block_a;

	block_a = 0;
	old_block_a = stack->a_count;
	if (block_b <= 2)
	{
		if (ft_sort_two(stack, instructions) == 0)
			return (0);
		if (ft_push_n_to_name(stack, block_b, 'a', instructions) == 0)
			return (0);
		return (1);
	}
	if (ft_split_block_b(block_b, stack, instructions) == 0)
		return (0);
	block_a = stack->a_count - old_block_a;
	block_b = block_b - block_a;
	if (block_a > 1)
	{
		if (ft_sort_block_a(block_a, stack, instructions) == 0)
			return (0);
	}
	if (ft_smart_rotate_b(block_b, stack, instructions) == 0)
		return (0);
	return (1);
}

int		ft_sort_block_a(int block_a, t_stacks *stack, t_list **instructions)
{
	int new_block_a;
	int new_block_b;
	int old_block_b;

	new_block_a = 0;
	new_block_b = 0;
	old_block_b = stack->b_count;
	if (block_a <= 3)
		if (ft_sort_to_four(stack, instructions, block_a) == 0)
			return (0);
	if (block_a > 3)
	{
		if (is_sorted(stack->a, stack->a_count) == 0)
		{
			if (ft_split_block_a(block_a, stack, instructions) == 0)
				return (0);
			new_block_b = stack->b_count - old_block_b;
			new_block_a = block_a - new_block_b;
		}
		if (ft_smart_rotate_a(new_block_a, stack, instructions) == 0)
			return (0);
	}
	if (ft_sort_block_b(new_block_b, stack, instructions) == 0)
		return (0);
	return (1);
}
