/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stacks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 14:55:16 by fcahill           #+#    #+#             */
/*   Updated: 2019/07/10 14:55:21 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	arg_is_number(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
	{
		if (arg[i] == '+' || arg[i] == '-')
			++i;
		if (ft_isdigit(arg[i]) == 0 && ft_isspace(arg[i]) == 0)
			return (0);
		if (ft_isdigit(arg[i]) == 1)
		{
			while (ft_isdigit(arg[i]) == 1)
				++i;
			if (arg[i] != '\0' && ft_isspace(arg[i]) == 0)
				return (0);
		}
		if (arg[i] != '\0')
			++i;
	}
	return (1);
}

int			ft_is_single_arg(char *arg)
{
	int	i;
	int	number_found;

	number_found = 0;
	i = 0;
	while (arg[i] != '\0')
	{
		if (arg_is_number(&arg[i]) == 0)
			return (-1);
		while (arg[i] != '\0' && (arg[i] == '+' ||
			arg[i] == '-' || (ft_isspace(arg[i]) == 1)))
			++i;
		if (ft_isdigit(arg[i]) == 1)
			++number_found;
		while (ft_isdigit(arg[i]) == 1)
			++i;
	}
	return (number_found);
}

static int	ft_save_args(int *a, int *b, char *arg, int quantity_arguments)
{
	if ((arg_is_number(arg) == 0))
		return (0);
	a[0] = ft_atoi(arg);
	b[0] = 0;
	++quantity_arguments;
	return (quantity_arguments);
}

static int	ft_find_next_number(char *arg, int i)
{
	while (ft_isspace(arg[i]) == 1 || arg[i] == '-' || arg[i] == '+')
		++i;
	while (ft_isdigit(arg[i]) == 1)
		++i;
	while (arg[i] != '\0' && ft_isspace(arg[i]) == 1)
		++i;
	return (i);
}

int			ft_create_stacks(int *a, int *b, char **arg)
{
	int	i;
	int	s;
	int	k;

	i = 0;
	s = 0;
	while (arg[i])
	{
		if (ft_is_single_arg(arg[i]) == 1)
			if ((s = ft_save_args(&a[s], &b[s], arg[i], s)) == 0)
				return (0);
		if (ft_is_single_arg(arg[i]) != 1)
		{
			k = 0;
			while (arg[i][k] != '\0')
			{
				if ((s = ft_save_args(&a[s], &b[s], &arg[i][k], s)) == 0)
					return (0);
				k = ft_find_next_number(arg[i], k);
			}
		}
		++i;
	}
	return (1);
}
