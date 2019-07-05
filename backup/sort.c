#include "pushswap.h"
int     ft_split_block_a(int block_a, t_stacks *stack, t_list **instructions)
{
    int median;
    int block_b;

    block_b = 0;
    median = find_median(stack->a, block_a);
    //sprintf("median = %d\n", median);
    while (block_a-- != 0)
    {
          if (stack->a[0] <= median)
        {
            if (ft_move_and_save("pb", stack, instructions) == 0)
                return (0);
        }
        else
        {
            if (ft_move_and_save("ra", stack, instructions) == 0)
                return (0);
        }
    }
    return(1);
}

int     ft_split_block_b(int block_b, t_stacks *stack, t_list **instructions)
{
    int median;
    int block_a;

    block_a = 0;
    median = find_median(stack->b, block_b);
  
    while (block_b-- != 0)
    {
          if (stack->b[0] >= median)
        {
            if (ft_move_and_save("pa", stack, instructions) == 0)
                return (0);
        }
        else
            if (ft_move_and_save("rb", stack, instructions) == 0)
                return (0);
    }
    return(1);
}

int     ft_push_to_a(int block_b, t_stacks *stack, t_list**instructions)
{
    int     old_a;

    old_a = stack->a_count;
    
 //   printf("push to a called sort block b here = %d\n", block_b);                                        
    ft_sort_block_b(block_b, stack, instructions);
    if (stack->a_count != old_a + block_b)
     {
//         printf("push to a called push to a\n");
        block_b = block_b - (stack->a_count - old_a);
        ft_push_to_a(block_b, stack, instructions);
     }
    return (1);
}  

int     ft_push_to_b(t_stacks *stack, t_list **instructions)
{
    int     median;
    int     block_a;
    int     old_block_b;


    block_a = stack->a_count;
    old_block_b = stack->b_count;
    if (ft_split_block_a(block_a, stack, instructions) == 0)
        return (0);
    if (stack->a_count > 0)
    {
//        printf("push b calling push b");
        if (ft_push_to_b(stack, instructions) == 0)
            return (0);
    }
 //   printf("push to b calling push to a\n");
 //   printf("block = %d\n", stack->b_count - old_block_b);

    if (ft_push_to_a(stack->b_count - old_block_b, stack, instructions) == 0)
            return (0);
   
        return (1);
}

        