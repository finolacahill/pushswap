#include "libft/libft.h"
#include "libft/get_next_line.h"
#include "pushswap.h"


void    ft_print_stacks(int *a, int *b) 
{
    while ((*a) || (*b))
    {
        if (*a)
            ft_putnbr(*a);
        else
            ft_putchar(' ');
        ft_putchar(' ');
        if (*b)
            ft_putnbr(*b);
        else
            ft_putchar(' ');
        ft_putchar('\n');
        ++a;
        ++b;
    }
    ft_putstr("- -\n");
    ft_putstr("a b\n");
} 

void    ft_swapthem(int* stack)
{
    int    temp;

    temp = stack[0];
    if (stack)
    {
        stack[0] = stack[1];
        stack[1] = temp;       
    }
}
//pushing element from stack 1 onto stack 2
void   ft_push(int* a, int* b)
{
    int     len;
    
    len = sizeof(b);
    if (a[0])
    {
        while (len > 0)
        {
            b[len] = b[len - 1];
            --len;
        }
        b[0] = a[0];
        len = 0;
        while (a[len] != '\0')
        {
            a[len] = a[len + 1];
            ++len;
        }
    }
}

void    ft_rotate(int* stack)
{
    int     i;
    int     temp;

    i = 0;
    temp = stack[0];
    if (stack)
    {
        while (stack[i + 1] != '\0')
        {
            stack[i] = stack[i + 1];
            ++i;
        }
        stack[i] = temp;
    }
}

void    ft_revrotate(int* stack)
{
    int     i;
    int    temp;

    i = sizeof(stack);
    i--;
    temp = stack[i];
    if (stack)
    {
        while (i != 0)
        {
            stack[i] = stack[i - 1];
            --i;
        }
        stack[i] = temp;
    }
}

void    ft_move(char* instruction, int* a, int *b)
{
    if (ft_strcmp(instruction, "sa") == 0 || ft_strcmp(instruction, "ss") == 0) 
        ft_swapthem(a);
    if (ft_strcmp(instruction, "sb") == 0 || ft_strcmp(instruction, "ss") == 0)
        ft_swapthem(b); 
    if (ft_strcmp(instruction, "pa") == 0 )
        ft_push(b, a);
    if (ft_strcmp(instruction, "pb") == 0 )
        ft_push(a, b);
    if (ft_strcmp(instruction, "ra") == 0 || ft_strcmp(instruction, "rr") == 0)
        ft_rotate(a);
    if (ft_strcmp(instruction, "rb") == 0 || ft_strcmp(instruction, "rr") == 0)
        ft_rotate(b);
    if (ft_strcmp(instruction, "rra") == 0 || ft_strcmp(instruction, "rrr") == 0)
        ft_revrotate(a);
    if (ft_strcmp(instruction, "rrb") == 0 || ft_strcmp(instruction, "rrr") == 0)
        ft_revrotate(b);
}

int    main(int argc, char **argv)
{
    int     i;
    int     a[argc - 1];
    int     b[argc - 1];
    char    *instruction;
    
    i = 1;
    if (argc > 1)
    {
       // if (!(a = (char *)malloc(sizeof(int) * argc)))
         //   ft_putstr("Malloc Error");
      //  if (!(b = (char *)malloc(sizeof(int) * argc)))
        //    ft_putstr("Malloc Error");
       
        while (i < argc)
        {
            a[i - 1] = ft_atoi(argv[i]);
            ++i;
        }
        i = 0;
        printf("%lu\n", sizeof(b));
        while (a[i])
        {
            printf("%d\n", a[i]);
            ++i;
        }
 //       printf("%d\n", b[0]);
       // if (b[0] == '\0')
          //  printf("true");
      //  while (get_next_line(1, &instruction) > 0)
        //    ft_move(instruction, a, b);    
    }
   // ft_print_stacks(a, b);
    return (0);
    
}

