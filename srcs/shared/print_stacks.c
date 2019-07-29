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

#include "../../pushswap.h"

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
	while (i++ < ((len * 2) + 5))
		ft_putchar('-');
	ft_putchar('\n');
}

static void	ft_print_spaced_numbers(int a, int b, int len)
{
	int		len_a;
	int		len_b;

	len_a = len - ft_numlen(a);
	len_b = len - ft_numlen(b);
	ft_printf("|%d", a);
	while (len_a-- >= 0)
		ft_putchar(' ');
	ft_printf("|%d", b);
	while (len_b-- >= 0)
		ft_putchar(' ');
	ft_printf("|\n");
}

static void	ft_print_labels(int len)
{
	int		i;

	i = 0;
	while (i++ < len / 3)
		ft_putchar(' ');
	ft_putchar('a');
	while (i++ < len + 4)
		ft_putchar(' ');
	ft_printf("b\n");
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
		ft_print_spaced_numbers(stack->a[i], stack->b[i], len);
		++i;
	}
	ft_print_border(len);
	ft_print_labels(len);
}
