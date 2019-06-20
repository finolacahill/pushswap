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

void		ft_move(char *move, t_stacks *stack)
{
	if (ft_strcmp(move, "sa") == 0 || ft_strcmp(move, "ss") == 0)
		ft_swapthem(stack->a, stack->a_count);
	if (ft_strcmp(move, "sb") == 0 || ft_strcmp(move, "ss") == 0)
		ft_swapthem(stack->b, stack->b_count);
	if (stack->b_count > 0 && ft_strcmp(move, "pa") == 0)
		ft_push_a(stack);
	if (stack->a_count > 0 && ft_strcmp(move, "pb") == 0)
		ft_push_b(stack);
	if (ft_strcmp(move, "ra") == 0 || ft_strcmp(move, "rr") == 0)
		ft_rotate(stack->a, stack->a_count);
	if (ft_strcmp(move, "rb") == 0 || ft_strcmp(move, "rr") == 0)
		ft_rotate(stack->b, stack->b_count);
	if (ft_strcmp(move, "rra") == 0 || ft_strcmp(move, "rrr") == 0)
		ft_revrotate(stack->a, stack->a_count);
	if (ft_strcmp(move, "rrb") == 0 || ft_strcmp(move, "rrr") == 0)
		ft_revrotate(stack->b, stack->b_count);
	printf("move = %s\n", move);
	ft_print_stacks(stack);
}

int		ft_move_and_save(char *move, t_stacks *stack, t_list **instructions)
{
	t_list *new_move;
	char	*str;
	int		len;

	len = ft_strlen(move);
	//ft_printf("mve = %s\n", move);
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	ft_strcpy(str, move);
	ft_move(move, stack);
	if (!(new_move = ft_lstnew(&*str, len)))
		return (0);
	ft_lstaddend(*instructions, new_move);
	return (1);
}