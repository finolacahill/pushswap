#include "pushswap.h"

int    ft_sort_two(t_stacks *stack, t_list **instructions)
{

    if (stack->a_count >= 2 && stack->a[0] > stack->a[1])
    {
        if (stack->b_count >= 2 && stack->b[0] < stack->b[1])
        {
            if (ft_move_and_save("ss", stack, instructions) == 0)
				return (0);
        }
        else
        {
            if (ft_move_and_save("sa", stack, instructions) == 0)
				return (0);
        }
    }
   else
    {
        if (stack->b_count >= 2 && stack->b[0] < stack->b[1])
        {
            if (ft_move_and_save("sb", stack, instructions) == 0)
				return (0);
        }
    }    
	return (1);
}

int     ft_sort_three(t_stacks *stack, t_list **instructions)
{
   
	if (stack->a_count == 3)
	{ 
		if ( stack->a[0] > stack->a[1] 
			&& stack->a[0] > stack->a[2] && stack->a[1] < stack->a[2])
		{
			if (ft_move_and_save("ra", stack, instructions) == 0)
				return (0);
			return (1);
		}
		if (stack->a[2] < stack->a[1] && stack->a[2] < stack->a[0])
		 	{
			if (ft_move_and_save("rra", stack, instructions) == 0)
				return (0);
			if (ft_sort_two(stack, instructions) == 0)
				return (0);
			return (1);
		}
	}
	if (ft_sort_two(stack, instructions) == 0)
		return (0);
    if (stack->a[2] < stack->a[1] || stack->a[2] < stack->a[0])
    {
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

int		ft_sort_four(t_stacks *stack, t_list **instructions)
{
	int median;
	int move;
	int	block_b;
	int rev;

	rev = 0;
	median = find_median(stack->a, 4);
	move = 0;
	block_b = 0;
	if (is_sorted(stack->a, 4) == 0)
	{
	while (move++ != 4 && block_b != 2)
	{
		if (stack->a[0] < median)
		{
			++block_b;
			if (ft_move_and_save("pb", stack, instructions) == 0)
				return (0);
		}
		if (stack->a[0] >= median && block_b < 3)
		{
			++rev;
			if (ft_move_and_save("ra", stack, instructions) == 0)
				return (0);
		}
	}
	while (stack->a_count + block_b > 4 && rev-- != 0)
	{
		if (ft_move_and_save("rra", stack, instructions) == 0)
			return (0);
	}
	if (ft_sort_two(stack,instructions) == 0)
		return (0);
	}
	while (block_b-- != 0)
	{
		if (ft_move_and_save("pa", stack, instructions) == 0)
			return (0);
	}
	return (1);
}
	

int    ft_sort_five(t_stacks *stack, t_list **instructions)
{

	int pivot;
    int move;
	int block_b;
	int	rev;

	rev = 0;
	block_b = 0;
	move = 0;
	pivot = find_median(stack->a, 5);
	if (is_sorted(stack->a, 5) == 0)
	{
	while (move++ < 5 && block_b != 2)
    {
		if (stack->a[0] < pivot)
		{
			++block_b;
			if (ft_move_and_save("pb", stack, instructions) == 0)
				return (0);
		}
        if (stack->a[0] >= pivot)
		{
			++rev;
            if (ft_move_and_save("ra", stack, instructions) == 0)
				return (0);
		}
	}
	while ((stack->b_count > 3 && stack->b_count < 6) && rev-- != 0)
	{
		if (ft_move_and_save("ra", stack, instructions) == 0)
			return (0);
	}
	while ((stack->b_count >= 7 && rev-- > 0))
	{
		if (ft_move_and_save("rra", stack, instructions) == 0)
			return (0);
	}
	if (ft_sort_three(stack, instructions) == 0)
		return (0);
	if (ft_sort_two(stack, instructions) == 0)
		return (0);
	if (ft_push_n_to_name(stack, 2, 'a', instructions) == 0)
		return (0);
	}
	return (1);
}
/*
int		ft_sort_ten(t_stacks *stack, char name, int len, t_list **instructions)
{	
	int pivot; 
	int moves;
	int push = 0;

	
	pivot = find_median(stack, name);
	moves = 0;

	while (moves++ < len)
	{
		if (name == 'a')
		{
			if (stack->a[0] < pivot)
			{
				++push;
            	if (ft_move_and_save("pb", stack, instructions) == 0)
					return (0);
			}
        	if (stack->a[0] >= pivot)
            	if (ft_move_and_save("ra", stack, instructions) == 0)
					return (0);
        }
		if (name == 'b')
        {
			if (stack->b[0] >= pivot)
			{
            	if (ft_move_and_save("pa", stack, instructions) == 0)
					return (0);
				++push;
			}
        	if(stack->b[0] < pivot)
            	if (ft_move_and_save("rb", stack, instructions) == 0)
					return (0);
        }
	}	
	if (ft_sort_to_ten(stack, 'a', instructions) == 0)
		return (0);
	if (ft_sort_to_ten(stack, 'b', instructions) == 0)
		return (0);
	if (ft_push_all_to_name(stack, name, instructions) == 0)
		return (0);

	return (1);
}

int		ft_sort_to_five(t_stacks *stack, char name, t_list **instructions)
{
	int len;

	if (name == 'a')
		len = stack->a_count;
	if (name == 'b')
		len = stack->b_count;

	//	printf(" %c = %d\n", name, len);
	//if ()
	if (len == 2)
		if (ft_sort_two(stack, instructions) == 0)
			return (0);
	if (len == 3)
		if (ft_sort_three(stack, name, instructions) == 0)
			return (0);
	if  (len == 4)
		if (ft_sort_four(stack, name, instructions) == 0)
			return (0);
	if (len == 5)
		if (ft_sort_five(stack, name, instructions) == 0)
			return (0);
	return (1);
}
	
*/