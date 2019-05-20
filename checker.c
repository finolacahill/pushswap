#include "pushswap.h"

static void ft_create_stacks(int *a, int *b, int copy)
{
    a[0] = copy;
    b[0] = 0;
}

static int b_is_empty(int count_b)
{
    return (count_b == 0);
}

static int a_is_sorted(int *a, int count_a)
{
    while (--count_a > 0)
    {
        if (a[count_a] < a[count_a - 1])
            return (0);
    }
    return (1);
}
static int arg_is_number(char *arg)
{
    int     i;

    i = 0;
    while (arg[i] != '\0')
    {
        if (ft_isdigit(arg[i]) == 0 && arg[i] != ' ')
            return (0);
        ++i;
    }
    return (1);
}

int    main(int argc, char **argv)
{
    t_count     count;
    int         a[argc - 1];
    int         b[argc - 1];
    char        *instruction;
    
    count.a = 0;
    count.b = 0;
    if (argc > 1)
    {       
        while (++count.a < argc)
        {
            if (arg_is_number(argv[count.a]) == 1)
                ft_create_stacks(&a[count.a - 1], &b[count.a - 1], ft_atoi(argv[count.a]));
            else
                return(ft_pushswap_usage());
         }
         --count.a;
        ft_print_stacks(a, b, &count); // mini visu to be deleted later
        while (get_next_line(1, &instruction) > 0)
         {
            ft_move(instruction, a, b, &count);    
            ft_print_stacks(a, b, &count); //mini visu to be deleted later
         }
        if ((b_is_empty(count.b)) && (a_is_sorted(a, count.a)))
            return(ft_pushswap_ok());
        else
            return(ft_pushswap_ko());  
    }
    return (ft_pushswap_usage());
}

