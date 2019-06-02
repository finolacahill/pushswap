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

  //  if (stack->a_count == 3)
   // {
        ft_sort_two(stack);
        if (name == 'a') 
        {
            if (stack->a[2] < stack->a[1] || stack->a[2] < stack->a[0])
            {
                ft_move("rra", stack);
                ft_sort_two(stack);
            }
        }
        if (name == 'b')
        {
            if (stack->b[2] > stack->b[1] || stack->b[2] > stack->b[0])
            {
                ft_move("rrb", stack);
                ft_sort_two(stack);
            }
        }
        

 //   }
    

}

void    ft_sort_five(t_stacks *stack, char name)
{
    int pivot;
    int rev;
    int push;

    rev = 0;
    push = 0;

    if (name == 'a') 
    {
        pivot = find_median(stack->a, 0, stack->a_count);
        while (rev + push < 5)
        {
            if (stack->a[0] < pivot)
            {
                ft_move("pb", stack);
                ++push;
            }
            if (stack->a[0] >= pivot)
            {
             ft_move("ra", stack);
             ++rev;
            }
        }
    }
    if (name == 'b')
    {
        pivot = find_median(stack->b, 0, stack->b_count);
     
        if (push == 2)
        {
            ft_sort_two(stack);
            ft_sort_three(stack, name);
            if (name == 'a')
            {
                ft_move("pa", stack);
                ft_move("pa", stack);
            }   
            if (name == 'b')
            {
                ft_move("pb", stack);
                ft_move("pb", stack);
            } 
        }
   }
}

//void    ft_sort_ten(t_stacks &stack);