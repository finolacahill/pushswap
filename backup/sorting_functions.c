#include "pushswap.h"

void    ft_push_n_to_name(t_stacks *stack, int n, char name)
{
    int i;

    i = 0;
    while (i < n)
    {
        if (name == 'a')
            ft_move("pa", stack);
        if (name == 'b')
            ft_move("pb", stack);
        ++i;
    }
}

void    ft_push_all_to_name(t_stacks *stack, char name)
{
    int len;
    int n;

    len = 0;
    if (name == 'a')
    {
        n = stack->b_count;
        while (len++ < n)
            ft_move("pa", stack);
    }
    if (name == 'b')
    {
        n = stack->a_count;
        while (len++ < n)
            ft_move("pb", stack);
    }
}
static void ft_move_up(t_stacks *stack, char name, int steps)
{
    printf("steps = %d\n", steps);
    while (steps != 0)
    {
        if (name == 'a')
            ft_move("ra", stack);
        ft_print_stacks(stack);
        if (name == 'b')
            ft_move("rb", stack);
        --steps;
     }
}

static void ft_move_down(t_stacks *stack, char name, int steps)
{
    while (steps != 0)
    {
        if (name == 'a')
            ft_move("rra", stack);
        if (name == 'b')
            ft_move("rrb", stack);
        --steps;
        }
}

void    ft_move_to_top(t_stacks *stack, char name, int index)
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
            ft_move_up(stack, name, up);
        else
            ft_move_down(stack, name, down);
    }
        
}