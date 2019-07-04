#include "pushswap.h"



int    ft_push_n_to_name(t_stacks *stack, int n, char name, t_list **instructions)
{
    int i;

    i = 0;
    while (i < n)
    {
        if (name == 'a')
            if (ft_move_and_save("pa", stack, instructions) == 0)
                return (0);
        if (name == 'b')
            if (ft_move_and_save("pb", stack, instructions) == 0)
                return (0);
        ++i;
    }
    return (1);
}
/*
int    ft_push_all_to_name(t_stacks *stack, char name, t_list **instructions)
{
    int len;
    int n;

    len = 0;
    if (name == 'a')
    {
        n = stack->b_count;
        while (len++ < n)
            if (ft_move_and_save("pa", stack, instructions) == 0)
                return (0);
    }
    if (name == 'b')
    {
        n = stack->a_count;
        while (len++ < n)
            if (ft_move_and_save("pb", stack, instructions) == 
                return (0);
    }
    return (1);
}
*/
int ft_move_up(t_stacks *stack, char name, int steps, t_list **instructions)
{
    while (steps != 0)
    {
        if (name == 'a')
            if (ft_move_and_save("ra", stack, instructions) == 0)
                return (0);
        if (name == 'b')
            if (ft_move_and_save("rb", stack, instructions) == 0)
                return (0);
        --steps;
     }
     return (1);
}

int ft_move_down(t_stacks *stack, char name, int steps, t_list **instructions)
{
    while (steps != 0)
    {
        if (name == 'a')
            if (ft_move_and_save("rra", stack, instructions) == 0)
                return (0);
        if (name == 'b')
           if (ft_move_and_save("rrb", stack, instructions) == 0)
                return (0);
        --steps;
    }
    return (1);
}

int    ft_move_to_top(t_stacks *stack, char name, int index, t_list **instructions)
{
    int     up;
    int     down;
    int     len;

    down = 1;
    up = 1;
    if (index > 0)
    {
        if (name == 'a')
            len = stack->a_count;
        else
            len = stack->b_count;
        while (index - up != 0)
            ++up;
        while (index + down != len)
            ++down;
        if (up < down)
           {
             if (ft_move_up(stack, name, up, instructions) == 0)
                return (0);
           }
        else
            {
                if (ft_move_down(stack, name, down, instructions) == 0)
                return (0);
            }
    }
    return (1);
        
}