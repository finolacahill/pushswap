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

#include "../../pushswap.h"

void	ft_perf_quicksort(int *array, int first, int last)
{
	int i;
	int j;
	int pivot;

	if (first < last)
	{
		pivot = first;
		i = first;
		j = last - 1;
		while (i < j)
		{
			while (array[i] <= array[pivot] && i < last - 1)
				i++;
			while (array[j] > array[pivot])
				j--;
			if (i < j)
				ft_swap(&array[i], &array[j]);
		}
		ft_swap(&array[pivot], &array[j]);
		ft_perf_quicksort(array, first, j);
		ft_perf_quicksort(array, j + 1, last);
	}
}

void	ft_move(char *move, t_stacks *stack)
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
}

int		ft_move_and_save(char *move, t_stacks *s, t_list **instruc)
{
	t_list	*new_move;
	char	*str;
	int		len;

	len = ft_strlen(move);
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	ft_strcpy(str, move);
	ft_move(move, s);
	if (!(new_move = ft_lstnew(&*str, len + 1)))
		return (0);
	ft_lstaddend(*instruc, new_move);
	free(str);
	return (1);
}

int		ft_check_instructions(char *move)
{
	if (move[0] == 'r' && move[1] == 'r')
	{
		if (ft_strcmp(move, "rra") == 0 ||
			ft_strcmp(move, "rrb") == 0 ||
			ft_strcmp(move, "rrr") == 0)
			return (1);
	}
	if ((ft_strcmp(move, "sa") == 0) ||
		ft_strcmp(move, "sb") == 0 ||
		ft_strcmp(move, "ss") == 0 ||
		ft_strcmp(move, "ra") == 0 ||
		ft_strcmp(move, "rb") == 0 ||
		ft_strcmp(move, "rr") == 0 ||
		ft_strcmp(move, "pa") == 0 ||
		ft_strcmp(move, "pb") == 0)
		return (1);
	return (0);
}
