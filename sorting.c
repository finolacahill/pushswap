#include "pushswap.h"

int ft_smart_rotate_a(int block, t_stacks *stack, t_list **instructions)
{
	int block_a;
	int block_b;
	int rest;
	int median;

	rest = stack->a_count - block;
	block_a = block;
	block_b = 0;
	median = find_median(&stack->a[rest], block);
	if (block == stack->a_count)
		return (1);
	while (block-- != 0)
	{
		if (ft_move_and_save("rra", stack, instructions) == 0)
			return (0);
		if (stack->a[0] <= median)
		{
			if (ft_move_and_save("pb", stack, instructions) == 0)
				return (0);
			++block_b;
			--block_a;
		}
	}
	if (is_sorted(stack->a, block_a) == 0)
	{
		if (ft_sort_block_a(block_a,stack, instructions) == 0)
			return(0);
	}
	if (ft_sort_block_b(block_b, stack, instructions) == 0)
		return (0);
	return (1);
}

int ft_smart_rotate_b(int block, t_stacks *stack, t_list **instructions)
{
	int block_a;
	int block_b;
	int rest;
	int median;

	rest = stack->b_count - block;
	block_b = block;
	block_a = 0;
	median = find_median(&stack->b[rest], block);

	if (block == stack->b_count)
		return (1);
	while (block-- != 0)
	{
		if (ft_move_and_save("rrb", stack, instructions) == 0)
			return (0);
		if (stack->b[0] >= median)
		{
			if (ft_move_and_save("pa", stack, instructions) == 0)
				return (0);
			++block_a;
			--block_b;
		}
	}

	if (block_a > 1)
		ft_sort_block_a(block_a, stack, instructions);
	if (block_b > 0)
		ft_sort_block_b(block_b, stack, instructions);
	
	return (1);
}

int	ft_sort_block_b(int block_b, t_stacks *stack, t_list **instructions)
{
	int	block_a;
	int	old_block_a;

	block_a = 0;
//	printf("block b of %d stack of %d\n", block_b, stack->b_count);
	old_block_a = stack->a_count;
	if (ft_split_block_b(block_b,stack, instructions) == 0)
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
	//	ft_sort_block_b(block_b, stack, instructions);
	// ft_sort_block_a(block_a, stack, instructions);
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
	if (block_a <= 2)
		ft_sort_to_five(stack, instructions);
//	printf("block a of %d\n", block_a);
	if (is_sorted(stack->a, stack->a_count) == 0)
	{
		ft_split_block_a(block_a, stack, instructions);
		new_block_b = stack->b_count - old_block_b;
		new_block_a = block_a - new_block_b;
	}
	ft_smart_rotate_a(new_block_a, stack, instructions);
//	if (is_sorted(stack->a, new_block_a) == 0)
//	{
//		ft_sort_block_a(new_block_a, stack, instructions);
//	}
	ft_sort_block_b(new_block_b, stack, instructions);
	return (1);
}
