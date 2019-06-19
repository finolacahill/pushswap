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

int     ft_sort_three(t_stacks *stack, char name, t_list **instructions)
{
    if (ft_sort_two(stack, instructions) == 0)
		return (0);
	ft_print_stacks(stack);
    if (name == 'a') 
    {
        if (stack->a[2] < stack->a[1] || stack->a[2] < stack->a[0])
        {
            if (ft_move_to_top(stack, name, 2, instructions) == 0)
				return (0);
          	if (ft_sort_two(stack, instructions) == 0)
			  return (0);
        }
    }
    if (name == 'b')
    {
        if (stack->b[2] > stack->b[1] || stack->b[2] > stack->b[0])
        {
			if (ft_move_to_top(stack, name, 2, instructions) == 0)
				return (0);
            if (ft_sort_two(stack, instructions) == 0)
				return (0);	
        }
    }
	return (1);
}

int		ft_sort_four(t_stacks *stack, char name, t_list **instructions)
{
	int pivot;
	int move;

	pivot = find_median(stack, name);
	move = 0;
	while (move++ < 4)
	{
		if (name == 'a')
		{
			if (stack->a[0] < pivot)
				if (ft_move_and_save("pb", stack, instructions) == 0)
					return (0);
			if (stack->a[0] >= pivot)
				if (ft_move_and_save("ra", stack, instructions) == 0)
					return (0);
		}
		if (name == 'b')
		{
			if (stack->b[0] >= pivot)
				if (ft_move_and_save("pa", stack, instructions) == 0)
					return (0);
			if (stack->b[0] < pivot)
				if (ft_move_and_save("rb", stack, instructions) == 0)
					return (0);
		}
	}
	if (ft_sort_two(stack, instructions) == 0)
		return (0);
	if (ft_push_n_to_name(stack, 2, name, instructions) == 0)
		return (0);
	return (1);
}

int    ft_sort_five(t_stacks *stack, char name, t_list **instructions)
{
	ft_print_stacks(stack);
	int pivot;
    int move;
	int push;

	push = 0;
	move = 0;
	pivot = find_median(stack, name);
	while (move++ < 5)
    {
		if (name == 'a' && stack->a[0] < pivot)
		{
			++push;
			if (ft_move_and_save("pb", stack, instructions) == 0)
				return (0);
		}
        if (name == 'a' && stack->a[0] >= pivot)
            if (ft_move_and_save("ra", stack, instructions) == 0)
				return (0);
		if (name == 'b' && stack->b[0] >= pivot)
		{
			++push;
			if (ft_move_and_save("pa", stack, instructions) == 0)
				return (0);
		}
        if (name == 'b' && stack->b[0] < pivot)
            if (ft_move_and_save("rb", stack, instructions) == 0)
				return (0);
		ft_print_stacks(stack);
	}
	ft_print_stacks(stack);
    if (ft_sort_three(stack, name, instructions) == 0)
		return (0);
	if (ft_sort_three(stack, name, instructions) == 0)
		return (0);
	if (ft_push_n_to_name(stack, push, name, instructions) == 0)
		return (0);
	return (1);
}

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
	ft_print_stacks(stack);
	return (1);
}

int		ft_sort_to_ten(t_stacks *stack, char name, t_list **instructions)
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
	if (len > 5 && len <= 10)
		if (ft_sort_ten(stack, name, len, instructions) == 0)
			return (0);
	return (1);
}
	
