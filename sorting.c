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


void    ft_sort_a(t_stacks *stack, int first, int last)
{
    int pivot;
    int push;
    int rev;

    push = 0;
    rev = 0;

    if (is_sorted(stack->a, stack->a_count) == 0 || stack->b_count != 0)
    {
        if (is_sorted(stack->a, stack->a_count) == 0)
        {
        pivot = find_median(stack->a, first, last);
        while (push + rev < last - first)
        {
            if (stack->a[first] <= pivot)
                {
                    ft_move("pb", stack);
                    ft_printf("pb\n");
                    ++push;
                }
            if (stack->a[first] > pivot)
            {
                ft_move("ra\n", stack);
                ft_printf("ra\n");
                ++rev;
            }
        }
        }
        ft_print_stacks(stack);
//        ft_sort_b(&stack, 0, stack->b_count);
        //    ft_quicksort_b(stack, 0, );
  //  ft_quicksort(stack, pivot + 1, last);
    } 
      
}

/*void    ft_sort_b(t_stacks *stack, int first, int last)
{
    int pivot;
    int push;
    int rev;

    push = 0;
    rev = 0;
    if (is_sorted(stack->b, stack->b_count) == 0 || stack->a_count != 0)
    {
       pivot = find_median(stack->b, first, last);
        if (is_sorted(stack->b, stack->b_count) == 0)
        {
           while (push + rev < last - first)
            {
               if (stack->b[0] >= pivot)
                {
                    ft_move("pa", stack);
                    ft_printf("pa\n");
                  ++push;
                }
               if (stack->b[0] < pivot)
                 {  ft_move("rb", stack);
                  ft_printf("rb\n");
                   ++rev;
                 }
            }
            while (rev != 0)
            {
               ft_move("rrb", stack);
                ft_printf("rrb\n");
              --rev;
            }
        }
  //      ft_print_stacks(stack);
 //        ft_sort_a(stack, 0, push);
    }
   // ft_print_stacks(stack);
 // ft_sort_a(stack, 0, stack->a_count);
}
//PSEUDO CODE

// SORT THREE:
*/
int     find_median(int *array, int start, int end)
{
    int    *cpy;
    int    len;
    int    med;

    if (!(cpy = (int *)malloc(sizeof(int) * (end - start))))
        return (-1);
    cpy = ft_intarraycpy(array, cpy, end);
    len = end - start; //maybe a minus 1 here/ Doubts.
    ft_perf_quicksort(cpy, start, end);
    med = cpy[len / 2];
    free(cpy);
    return (med);
}

