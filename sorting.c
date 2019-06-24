#include "pushswap.h"

void ft_perf_quicksort(int *array,int first,int last)
{
    int i;
    int j; 
    int pivot;

    if (first < last)
    {
        pivot = first;
        i = first;
        j = last - 1;
        while(i < j)
        {
            while(array[i] <= array[pivot] && i < last - 1)
               i++;
           while(array[j]>array[pivot])
             j--;
         if (i < j)
             ft_swap(&array[i], &array[j]);
        }
        ft_swap(&array[pivot], &array[j]);
        ft_perf_quicksort(array, first, j);
        ft_perf_quicksort(array, j + 1, last);
    }   
}

int     find_median(int *stack, int len)
{
    int    cpy[len];
    int    med;

    ft_intarraycpy(stack, cpy, len);
    ft_perf_quicksort(cpy, 0, len);
    med = cpy[len / 2];
    printf("med = %d\n", med);
    return (med);
}

int		ft_sort_block(int push, char name, t_stacks *stack, t_list **instructions)
{
	if (name == 'a')
	{
		if (ft_sort_block_a(push, stack, instructions) == 0)
			return (0);
	}
	if (name == 'b')
	{
		if (ft_sort_block_b(push, stack, instructions) == 0)
			return (0);
	}
	return (1);
}

int	ft_sort_block_b(int push, t_stacks *stack, t_list **instructions)
{
	int median; 
	int	rev;
	int	block;

	median = find_median(stack->b, push);
	rev = 0;
	block = push;
	while (push-- != 0)
    {
        if (stack->b[0] >= median)
        {
            if (ft_move_and_save("pa", stack, instructions) == 0)
                return (0);
        }
        else
        {
            if (ft_move_and_save("rb", stack, instructions) == 0)
                return (0);
            rev++;            
        }
    }
	while (rev != 0)
    {
        if (ft_move_and_save("rrb", stack, instructions) == 0)
            return (0);
        --rev;
        ++push;
    }
	if (ft_sort_block_a(block, stack, instructions) == 0)
		return (0);
	if (push != 0)
		ft_sort_block_b(push,stack,instructions);
	return (1);
}

int		ft_sort_block_a(int push, t_stacks *stack, t_list **instructions)
{
	int median;
	int rev;
	int block;

	median = find_median(stack->a, push);
	rev = 0;
	block = 0;
	if (is_sorted(stack->a, stack->a_count) == 0)
	{
		if (stack->a[0] <= median)
		{	
			if (ft_move_and_save("pb", stack, instructions) == 0)
			return (0);
			++block;
		}
		else
		{
			{
				if (ft_move_and_save("ra",stack, instructions) == 0)
					return (0);
				++rev; 
			}
		}
		while (rev != 0)
    	{
        	if (ft_move_and_save("rra", stack, instructions) == 0)
            	return (0);
        	--rev;
       		++push;
    	}
	if (ft_sort_block_b(push, stack, instructions) == 0)
		return (0);
	}
	return (1);
}
