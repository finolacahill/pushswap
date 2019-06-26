#include "pushswap.h"

int     ft_sort_to_a(int push, t_stacks *stack, t_list**instructions)
{
    int     median;
    int     rev;
    ft_printf("push = %d\n", push);
    ft_print_stacks(stack);
    median = find_median(stack->b, push);
    rev = 0;
    while (push != 0)
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
        --push;
    }
    ft_print_stacks(stack);
    while (rev != 0)
    {
        if (ft_move_and_save("rrb", stack, instructions) == 0)
            return (0);
        --rev;
        ++push;
    }
    ft_print_stacks(stack);
    if (push != 0)
        ft_sort_to_a(push, stack, instructions);
    return (1);
}  


int     ft_sort_to_b(t_stacks *stack, t_list **instructions)
{
    int     median;
    int     i;
    int     push;

    push = 0;

    median = find_median(stack->a, stack->a_count);
    i = stack->a_count;
     while (i-- != 0)
    {
        if (stack->a[0] <= median)
        {
            if (ft_move_and_save("pb", stack, instructions) == 0)
                return (0);
                ++push; 
        }
        else
            if (ft_move_and_save("ra", stack, instructions) == 0)
                return (0);
    }
    ft_print_stacks(stack);
    if (stack -> a_count > 0)
        ft_sort_to_b(stack, instructions);
    ft_sort_to_a(push, stack, instructions);
    return (1);
}

