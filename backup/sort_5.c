#include "pushswap.h"

void    ft_sort_two(t_stacks *stack)
{
	printf("here 2\n");
    if (stack->a_count >= 2 && stack->a[0] > stack->a[1])
    {
        if (stack->b_count >= 2 && stack->b[0] < stack->b[1])
        {
            ft_move("ss", stack);
            ft_printf("ss");
        }
        else
        {
            ft_move("sa", stack);
            ft_printf("sa");
        }
    }
   else
    {
        if (stack->b_count >= 2 && stack->b[0] < stack->b[1])
        {
            ft_move("sb", stack);
            ft_printf("sb");
        }
    }    
}

void     ft_sort_three(t_stacks *stack, char name)
{
    ft_sort_two(stack);
	ft_print_stacks(stack);
    if (name == 'a') 
    {
        if (stack->a[2] < stack->a[1] || stack->a[2] < stack->a[0])
        {
            ft_move_to_top(stack, name, 2);
          	ft_sort_two(stack);
        }
    }
    if (name == 'b')
    {
        if (stack->b[2] > stack->b[1] || stack->b[2] > stack->b[0])
        {
			ft_move_to_top(stack, name, 2);
            ft_sort_two(stack);			
        }
    }
}

void	ft_sort_four(t_stacks *stack, char name)
{
	int pivot;
	int move;

	printf("here 4\n");
	pivot = find_median(stack, name);
	move = 0;
	while (move++ < 4)
	{
		if (name == 'a')
		{
			if (stack->a[0] < pivot)
				ft_move("pb", stack);
			if (stack->a[0] >= pivot)
				ft_move("ra", stack);
		}
		if (name == 'b')
		{
			if (stack->b[0] >= pivot)
				ft_move("pa", stack);
			if (stack->b[0] < pivot)
				ft_move("rb", stack);
		}
	}
	ft_sort_two(stack);
	ft_push_n_to_name(stack, 2, name);
}

void    ft_sort_five(t_stacks *stack, char name)
{
	printf("here 5\n");
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
			ft_move("pb", stack);
		}
        if (name == 'a' && stack->a[0] >= pivot)
            ft_move("ra", stack);
		if (name == 'b' && stack->b[0] >= pivot)
		{
			++push;
			ft_move("pa", stack);
		}
        if (name == 'b' && stack->b[0] < pivot)
            ft_move("rb", stack);
		ft_print_stacks(stack);
	}
	ft_print_stacks(stack);
    ft_sort_three(stack, name);
	ft_sort_two(stack);
	ft_push_n_to_name(stack, push, name);
}

void	ft_sort_ten(t_stacks *stack, char name, int len)
{	
	int pivot; 
	int moves;
	int push = 0;

	
	pivot = find_median(stack, name);
	printf("pivt = %d\n", pivot);
	moves = 0;

	while (moves++ < len)
	{
		if (name == 'a')
		{
			if (stack->a[0] < pivot)
			{
				++push;
            	ft_move("pb", stack);
			}
        	if (stack->a[0] >= pivot)
            	ft_move("ra", stack);
        }
		if (name == 'b')
        {
			if (stack->b[0] >= pivot)
			{
            	ft_move("pa", stack);
				++push;
			}
        	if(stack->b[0] < pivot)
            	ft_move("rb", stack);
        }
	}	
	ft_sort_to_ten(stack, 'a');
	ft_sort_to_ten(stack, 'b');
	//printf("do we arrive here?\n");
	ft_push_all_to_name(stack, name);
	ft_print_stacks(stack);
}

void	ft_sort_to_ten(t_stacks *stack, char name)
{
	int len;

	if (name == 'a')
		len = stack->a_count;
	if (name == 'b')
		len = stack->b_count;

	//	printf(" %c = %d\n", name, len);
	//if ()
	if (len == 2)
		ft_sort_two(stack);
	if (len == 3)
		ft_sort_three(stack, name);
	if  (len == 4)
		ft_sort_four(stack, name);
	if (len == 5)
		ft_sort_five(stack, name);
	if (len > 5 && len <= 10)
		ft_sort_ten(stack, name, len);
}
	
