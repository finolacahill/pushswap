#include "libft/libft.h"
#include "pushswap.h"

static int  find_longest_num(int *a, int *b, t_count *count)
{
    int i;
    int len;

    i = 0;
    len = 0;
    while (i < count-> a || i < count->b)
    {
        if (ft_numlen(a[i]) > len)
            len = ft_numlen(a[i]);
        if (ft_numlen(b[i]) > len)
            len = ft_numlen(b[i]);
        ++i;
    }
    return (len);

}

static void    ft_print_border(int len)
{
    int i;

    i = 0;
    while(i++ < ((len * 2) + 5))
        ft_putchar('-');
    ft_putchar('\n');
}

static void    ft_print_spaced_numbers(int a, int b, int len)
{
    int     len_a;
    int     len_b;

    len_a = len - ft_numlen(a);
    len_b = len - ft_numlen(b);
    ft_printf("|%d", a);
    while(len_a-- >= 0)
        ft_putchar(' ');
    ft_printf("|%d", b);
    while(len_b-- >= 0) 
        ft_putchar(' ');
     ft_printf("|\n");
}

static void    ft_print_labels(int len)
{
    int     i;

    i = 0;

    ft_putchar('a');
    while (i++ < len * 2 + 1)
        ft_putchar(' ');
    ft_printf("b\n");
}

void    ft_print_stacks(int *a, int *b, t_count *count) 
{
    int     i;
    int     len;

    i = 0;
 
    len = find_longest_num(a, b, count);
    ft_print_border(len);
    while (i < count->a || i < count->b)
    {
       ft_print_spaced_numbers(a[i], b[i], len);
        ++i;
    }
    ft_print_border(len);
    ft_print_labels(len);
    //to be deleted after//
    ft_printf("\ncount_a = %d\ncount_b = %d\n", count->a, count->b);
} 