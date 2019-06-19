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

void	ft_push(int *a, int *b, int count_a, int count_b)
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

void		ft_move(char *move, t_stacks *stack)
{
	if (ft_strcmp(move, "sa") == 0 || ft_strcmp(move, "ss") == 0)
		ft_swapthem(stack->a, stack->a_count);
	if (ft_strcmp(move, "sb") == 0 || ft_strcmp(move, "ss") == 0)
		ft_swapthem(stack->b, stack->b_count);
	if (stack->b_count > 0 && ft_strcmp(move, "pa") == 0)
	{
		ft_push(stack->b, stack->a, stack->b_count, stack->a_count);
		++stack->a_count;
		--stack->b_count;
	}
	if (stack->a_count > 0 && ft_strcmp(move, "pb") == 0)
	{
		ft_push(stack->a, stack->b, stack->a_count, stack->b_count);
		++stack->b_count;
		--stack->a_count;
	}
	if (ft_strcmp(move, "ra") == 0 || ft_strcmp(move, "rr") == 0)
		ft_rotate(stack->a, stack->a_count);
	if (ft_strcmp(move, "rb") == 0 || ft_strcmp(move, "rr") == 0)
		ft_rotate(stack->b, stack->b_count);
	if (ft_strcmp(move, "rra") == 0 || ft_strcmp(move, "rrr") == 0)
		ft_revrotate(stack->a, stack->a_count);
	if (ft_strcmp(move, "rrb") == 0 || ft_strcmp(move, "rrr") == 0)
		ft_revrotate(stack->b, stack->b_count);
}

int		ft_move_and_save(char *move, t_stacks *stack, t_list **instructions)
{
	t_list *new_move;

	ft_move(move, stack);
	if (!(new_move = ft_lstnew(&move, 1)))
		return (0);
	ft_lstadd(instructions, new_move);
	return (1);
}