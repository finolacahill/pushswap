#include "pushswap.h"

int ft_smart_rotate_a(int block, t_stacks *stack, t_list **instructions)
{
	int i;
	int rest;

	i = 0;
	rest = stack->a_count - block;
	if (block == stack->a_count)
		return (1);
	if (block <= rest)
	{
		while (block-- != 0)
		{
			if (ft_move_and_save("rra", stack, instructions) == 0)
				return (0);
		}
	}
	else if (block > rest)
	{
		while (i++ < rest)
		{
			if (ft_move_and_save("ra", stack, instructions) == 0)
				return (0);
		}
	}
	return (1);
}

int ft_smart_rotate_b(int block, t_stacks *stack, t_list **instructions)
{
	int i;
	int rest;

	i = 0;
	rest = stack->b_count - block;
	
	if (block == stack->b_count)
		return (1);
	if (block <= rest)
	{
		while (block-- != 0)
		{
			if (ft_move_and_save("rrb", stack, instructions) == 0)
				return (0);
		}
	}
	else if (block > rest)
	{
		while (i++ < rest)
		{
			if (ft_move_and_save("rb", stack, instructions) == 0)
				return (0);
		}
	}
	return (1);
}

int	ft_sort_block_b(int block_b, t_stacks *stack, t_list **instructions)
{
	int	block_a;
	int	old_block_a;

	block_a = 0;
	old_block_a = stack->a_count;
	if (ft_split_block_b(block_b,stack, instructions) == 0)
		return (0);
	block_a = stack->a_count - old_block_a;
	block_b = block_b - block_a;
	if (ft_smart_rotate_b(block_b, stack, instructions) == 0)
		return (0);
	if (block_a > 1)
	{
		if (ft_sort_block_a(block_a, stack, instructions) == 0)
			return (0);
	}
	if (block_b > 0)
		ft_sort_block_b(block_b, stack, instructions);
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
//	if (stack->a_count <= 5)
//		ft_sort_to_five(stack, instructions);
	if (is_sorted(stack->a, stack->a_count) == 0)
	{
		ft_split_block_a(block_a, stack, instructions);
		new_block_b = stack->b_count - old_block_b;
		new_block_a = block_a - new_block_b;
	}
	ft_smart_rotate_a(new_block_a, stack, instructions);
	if (is_sorted(stack->a, new_block_a) == 0)
	{
		ft_sort_block_a(new_block_a, stack, instructions);
	}
	ft_sort_block_b(new_block_b, stack, instructions);
	return (1);
}
