#include "pushswap.h"

int     ft_sort_to_a(int block_b, t_stacks *stack, t_list**instructions)
{
    int     median;
    int     rev;
    int     old_a;
    int     old_b;

    old_a = stack->a_count;
    old_b = stack->b_count;
    printf("block b here = %d\n", block_b);
    median = find_median(stack->b, block_b);
    rev = 0;                                           
    ft_sort_block_b(block_b, stack, instructions);
    if (stack->a_count != old_a + block_b)
     {
        block_b = block_b - (stack->a_count - old_a);
//      printf("recursively external call b\n");
        ft_sort_to_a(block_b, stack, instructions);
     }
    return (1);
}  


int     ft_sort_to_b(t_stacks *stack, t_list **instructions)
{
    int     median;
    int     block_a;
    int     block_b;

    block_b = 0;

    median = find_median(stack->a, stack->a_count);
    block_a = stack->a_count;
     while (block_a-- != 0)
    {
        if (stack->a[0] <= median)
        {
            if (ft_move_and_save("pb", stack, instructions) == 0)
                return (0);
                ++block_b; 
        }
        else
            if (ft_move_and_save("ra", stack, instructions) == 0)
                return (0);
    }
    if (stack->a_count > 0)
        ft_sort_to_b(stack, instructions);
  //  while (stack->b_count > 0)
//  printf("externally calling b, stack of %d\n", block_b);
   ft_sort_to_a(block_b, stack, instructions);
    return (1);
}

        