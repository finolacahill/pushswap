/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 11:25:27 by fcahill           #+#    #+#             */
/*   Updated: 2019/05/22 11:29:11 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	ft_count_numbers(char **arg, int limit)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (i < limit)
	{
		count = count + ft_is_single_arg(arg[i]);
		if (count < 0)
			return (count);
		++i;
	}
	return (count);
}

static int	a_is_sorted(int *a, int count_a)
{
	while (--count_a > 0)
	{
		if (a[count_a] < a[count_a - 1])
			return (0);
	}
	return (1);
}

static int	there_are_duplicates(int *a, int quantity_args)
{
	int		i;
	int		j;

	i = 0;
	while (i < quantity_args)
	{
		j = 0;
		while (j < quantity_args)
		{
			if (i != j && a[i] == a[j])
				return (1);
			++j;
		}
		++i;
	}
	return (0);
}

int			main(int argc, char **argv)
{
	t_count	count;
	int		*a;
	int		*b;
	char	*instruction;

	count.b = 0;
	if (argc > 1)
	{
		if ((count.a = ft_count_numbers(&argv[1], argc - 1)) < 0)
			return (ft_pushswap_error());
		if (!(a = (int *)malloc(sizeof(int) * count.a)))
			return (0);
		if (!(b = (int *)malloc(sizeof(int) * count.a)))
			return (0);
		if (!(ft_create_stacks(a, b, &argv[1])))
			return (ft_pushswap_error());
		if ((there_are_duplicates(a, count.a)) == 1)
			return (ft_pushswap_error());
		ft_print_stacks(a, b, &count); // mini visu to be deleted later
		while (get_next_line(1, &instruction) > 0)
		{
			ft_move(instruction, a, b, &count);
			ft_print_stacks(a, b, &count); //mini visu to be deleted later
		}
		if (count.b == 0 && (a_is_sorted(a, count.a)))
			return (ft_pushswap_ok());
		else
			return (ft_pushswap_ko());
	}
	return (0);
}
