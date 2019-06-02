#include "pushswap.h"
int     *ft_intarraycpy(int *source, int *dest, int n)
{
    int     i;

    i = 0;
    while (i < n)
    {
        dest[i] = source[i];
        ++i;
    }
    return (dest);
}

int     ft_buildstacks(t_stacks *stack, char **args)
{
    	if (!(stack->a = (int *)malloc(sizeof(int) * stack->a_count)))
			return (0);
		if (!(stack->b = (int *)malloc(sizeof(int) * stack->a_count)))
			return (0);
		if  (!(stack->c = (int *)malloc(sizeof(int) * stack->a_count)))
			return (0);
		if (!(ft_create_stacks(stack->a, stack->b, args)))
            return (0);
        stack->c = ft_intarraycpy(stack->a, stack->c, stack->a_count);
        ft_perf_quicksort(stack->c, 0, stack->a_count);
        return (1);
}