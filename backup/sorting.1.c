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
	int		i;

	i = 0;
    ft_intarraycpy(stack, cpy, len);
    ft_perf_quicksort(cpy, 0, len);
    med = cpy[len / 2];
    return (med);
}

int	ft_sort_block_b(int block_b, t_stacks *stack, t_list **instructions)
{
	int median; 
	int	rev;
	int	block_a;

	printf("\t \tblock is %d and stack contains %d elem\n", block_b, stack->b_count);
	median = find_median(stack->b, block_b);
	rev = 0;
	block_a = 0;
	while (block_b-- != 0)
    {
        if (stack->b[0] >= median)
        {
            if (ft_move_and_save("pa", stack, instructions) == 0)
                return (0);
			++block_a;
        }
        else
        {
            if (ft_move_and_save("rb", stack, instructions) == 0)
                return (0);
            rev++;            
        }
    }
	while (rev-- != 0)
    {
        if (ft_move_and_save("rrb", stack, instructions) == 0)
            return (0);

        ++block_b;
    }
//ft_print_block(stack->a, stack->a_count);
if (block_a > 0)
{
		printf("\tb called a\n");
	ft_sort_block_a(block_a, stack, instructions);

}
//if (block_b > 0)	
//{
//		printf("b called b\n");
//		ft_sort_block_b(block_b,stack,instructions);		
//}
	return (1);
}

int		ft_sort_block_a(int block_a, t_stacks *stack, t_list **instructions)
{
//	printf("\t \tblock is %d and stack contains %d elem\n", block_a, stack->a_count);
	int median;
	int rev;
	int block_b;

	median = find_median(stack->a, block_a);
	
	rev = 0;
	block_b = 0;
	if (block_a <= 2)
		ft_sort_two(stack, instructions);
	if (block_a == 3)
		ft_sort_three(stack, instructions);
	if (block_a == 4)
		ft_sort_four(stack, instructions);
	if (block_a == 5)
		ft_sort_five(stack, instructions);
	if (is_sorted(stack->a, stack->a_count) == 0)
	{
	//	if (block_a <= 2)
			ft_sort_two(stack, instructions);
		while (block_a-- != 0)
		{
			ft_sort_two(stack, instructions);
			if (stack->a[0] <= median)
			{	
				if (ft_move_and_save("pb", stack, instructions) == 0)
					return (0);	
				++block_b;
		}
		else
			{
				{
					if (ft_move_and_save("ra",stack, instructions) == 0)
						return (0);
					++rev; 
				}
			}
		}
		while (rev != 0)
    	{
        	if (ft_move_and_save("rra", stack, instructions) == 0)
            	return (0);
        	--rev;
       		++block_a;
    	}


	}
	if (is_sorted(stack->a, block_a) == 0)
	{
//		printf("\ta called a\n");
		ft_sort_block_a(block_a, stack, instructions);
	}
//	printf("\ta called b\n");
	ft_sort_block_b(block_b, stack, instructions);
	return (1);
}
