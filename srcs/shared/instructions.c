/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 16:33:54 by fcahill           #+#    #+#             */
/*   Updated: 2019/07/10 16:33:57 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pushswap.h"

void	ft_swapthem(int *stack, int count)
{
	int		temp;

	if (count > 1)
	{
		temp = stack[0];
		stack[0] = stack[1];
		stack[1] = temp;
	}
}

void	ft_push_a(t_stacks *stack)
{
	int		len;

	len = stack->a_count;
	while (stack->b_count > 0 && len > 0)
	{
		stack->a[len] = stack->a[len - 1];
		--len;
	}
	stack->a[0] = stack->b[0];
	len = 0;
	while (len != stack->b_count - 1)
	{
		stack->b[len] = stack->b[len + 1];
		++len;
	}
	stack->b[stack->b_count - 1] = 0;
	++stack->a_count;
	--stack->b_count;
}

void	ft_push_b(t_stacks *stack)
{
	int		len;

	len = stack->b_count;
	while (stack->a_count > 0 && len > 0)
	{
		stack->b[len] = stack->b[len - 1];
		--len;
	}
	stack->b[0] = stack->a[0];
	len = 0;
	while (len != stack->a_count - 1)
	{
		stack->a[len] = stack->a[len + 1];
		++len;
	}
	stack->a[stack->a_count - 1] = 0;
	++stack->b_count;
	--stack->a_count;
}

void	ft_rotate(int *stack, int count)
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

void	ft_revrotate(int *stack, int count)
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
