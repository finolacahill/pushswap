/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 11:39:31 by fcahill           #+#    #+#             */
/*   Updated: 2019/05/22 11:43:23 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	find_longest_num(t_stacks *stack)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (i < stack->a_count || i < stack->b_count)
	{
		if (ft_numlen(stack->a[i]) > len)
			len = ft_numlen(stack->a[i]);
		if (ft_numlen(stack->b[i]) > len)
			len = ft_numlen(stack->b[i]);
		++i;
	}
	return (len);
}

static void	ft_print_border(int len)
{
	int		i;

	i = 0;
	while (i++ < ((len * 3) + 7))
		ft_putchar('-');
	ft_putchar('\n');
}

static void	ft_print_spaced_numbers(int a, int b, int c, int len)
{
	int		len_a;
	int		len_b;
	int		len_c;

	len_a = len - ft_numlen(a);
	len_b = len - ft_numlen(b);
	len_c = len - ft_numlen(c);
	ft_printf("|%d", a);
	while (len_a-- >= 0)
		ft_putchar(' ');
	ft_printf("|%d", b);
	while (len_b-- >= 0)
		ft_putchar(' ');
	ft_printf("|%d", c);
	while (len_c-- >= 0)
		ft_putchar(' ');
	ft_printf("|\n");
}

static void	ft_print_labels(int len)
{
	int		i;

	i = 0;
	while (i++ < len/3)
		ft_putchar(' ');
	ft_putchar('a');
	while (i++ < len + 4)
		ft_putchar(' ');
	ft_printf("b");
	while (i++ < (len + 4)* 2)
		ft_putchar(' ');
	ft_printf("c\n");
}

void		ft_print_stacks(t_stacks *stack)
{
	int		i;
	int		len;

	i = 0;
	len = find_longest_num(stack);
	ft_print_border(len);
	while (i < stack->a_count || i < stack->b_count)
	{
		ft_print_spaced_numbers(stack->a[i], stack->b[i], stack->c[i], len);
		++i;
	}
	ft_print_border(len);
	ft_print_labels(len);
//	ft_printf("\ncount_a = %d\ncount_b = %d\n", stack->a_count, stack->b_count);
}

void	ft_print_block(int *stack, int block)
{
	int i;

	i = 0;
	ft_printf("-------------\n");
	while (i != block)
	{
		ft_printf("%d\n", stack[i]);
		++i;
	}
	ft_printf("-------------\n");
	if (is_sorted(stack, block) == 0)
		ft_printf("Not sorted.\n");
	else
		ft_printf("Is sorted\n");
		
	}