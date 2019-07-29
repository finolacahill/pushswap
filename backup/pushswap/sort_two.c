/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 18:38:11 by fcahill           #+#    #+#             */
/*   Updated: 2019/07/10 18:38:13 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int			ft_sort_two(t_stacks *stack, t_list **instructions)
{
	if (stack->a_count >= 2 && stack->a[0] > stack->a[1])
	{
		if (stack->b_count >= 2 && stack->b[0] < stack->b[1])
		{
			if (ft_move_and_save("ss", stack, instructions) == 0)
				return (0);
		}
		else
		{
			if (ft_move_and_save("sa", stack, instructions) == 0)
				return (0);
		}
	}
	else
	{
		if (stack->b_count >= 2 && stack->b[0] < stack->b[1])
		{
			if (ft_move_and_save("sb", stack, instructions) == 0)
				return (0);
		}
	}
	return (1);
}
