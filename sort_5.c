#include "pushswap.h"

void    ft_sort_two(t_stacks *stack)
{
    if (stack->a[0] > stack->a[1])
    {
        if (stack->b[0] < stack->b[1])
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
        if (stack->b[0] < stack->b[1])
        {
            ft_move("sb", stack);
            ft_printf("sb");
        }
    }
    
}

void     ft_sort_three(t_stacks *stack, char name)
{
    ft_sort_two(stack);

    if (name == 'a' && stack->a_count == 3)
    {
        ft_sort_two(stack);
        if (stack->a[2] < stack->a[1] || stack->a[2] < stack->a[0])
            {
                ft_move ("rra", stack);
                ft_sort_two(stack);
            }

    }

}

void    ft_sort_five(t_stacks *stack, char name)
{
    int pivot;
    int rev;
    int push;

    rev = 0;
    push = 0;
    if (name == 'a' && stack->a_count == 5) 
    {
        pivot = find_median(stack->a, 0, stack->a_count);
        while (rev + push < 5)
        {
            if (stack->a[0] < pivot)
            {
                ft_move("pb", stack);
                ++push;
                ft_print_stacks(stack);
            }
            if (stack->a[0] >= pivot)
            {
             ft_move("ra", stack);
             ++rev;
             ft_print_stacks(stack);
            }
        }
        if (push == 2)
        {
            ft_sort_two(stack);
            ft_sort_three(stack, 'a');
            ft_move("pa", stack);
            ft_move("pa", stack);
        }
   }
}
