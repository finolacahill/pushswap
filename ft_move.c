/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 11:35:41 by fcahill           #+#    #+#             */
/*   Updated: 2019/05/22 11:38:57 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	ft_swapthem(int *stack, int count)
{
	int		temp;

	if (count > 1)
	{
		temp = stack[0];
		stack[0] = stack[1];
		stack[1] = temp;
	}
}

static void	ft_push(int *a, int *b, int count_a, int count_b)
{
	int		len;

	len = count_b;
	if (count_a > 0)
	{
		while (len > 0)
		{
			b[len] = b[len - 1];
			--len;
		}
		b[0] = a[0];
		len = 0;
		while (len != count_a - 1)
		{
			a[len] = a[len + 1];
			++len;
		}
		a[count_a - 1] = 0;
	}
}

static void	ft_rotate(int *stack, int count)
{
	int		i;
	int		temp;

	i = 0;
	temp = stack[0];
	if (count > 1)
	{
		while (i < count - 1)
		{
			stack[i] = stack[i + 1];
			++i;
		}
		stack[i] = temp;
	}
}

static void	ft_revrotate(int *stack, int count)
{
	int		temp;

	if (count > 1)
	{
		temp = stack[count - 1];
		while (count - 1 != 0)
		{
			stack[count - 1] = stack[count - 2];
			--count;
		}
		stack[count - 1] = temp;
	}
}

void		ft_move(char *move, int *a, int *b, t_count *count)
{
	if (ft_strcmp(move, "sa") == 0 || ft_strcmp(move, "ss") == 0)
		ft_swapthem(a, count->a);
	if (ft_strcmp(move, "sb") == 0 || ft_strcmp(move, "ss") == 0)
		ft_swapthem(b, count->b);
	if (count->b > 0 && ft_strcmp(move, "pa") == 0)
	{
		ft_push(b, a, count->b, count->a);
		++count->a;
		--count->b;
	}
	if (count->a > 0 && ft_strcmp(move, "pb") == 0)
	{
		ft_push(a, b, count->a, count->b);
		++count->b;
		--count->a;
	}
	if (ft_strcmp(move, "ra") == 0 || ft_strcmp(move, "rr") == 0)
		ft_rotate(a, count->a);
	if (ft_strcmp(move, "rb") == 0 || ft_strcmp(move, "rr") == 0)
		ft_rotate(b, count->b);
	if (ft_strcmp(move, "rra") == 0 || ft_strcmp(move, "rrr") == 0)
		ft_revrotate(a, count->a);
	if (ft_strcmp(move, "rrb") == 0 || ft_strcmp(move, "rrr") == 0)
		ft_revrotate(b, count->b);
}
