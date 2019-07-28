/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 11:25:27 by fcahill           #+#    #+#             */
/*   Updated: 2019/07/28 17:36:45 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	stack_normalizer(t_stacks *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->a_count)
	{
		j = 0;
		while (j < stack->a_count)
		{
			if (stack->a[i] == stack->c[j])
			{
				stack->a[i] = j + 1;
				j = stack->a_count;
			}
			++j;
		}
		++i;
	}
}

static int	checker(int flag, int i, int argc, char **argv)
{
	t_stacks	stack;
	char		*instruction;

	stack.b_count = 0;
	if ((stack.a_count = ft_count_numbers(&argv[i], argc - i)) < 0)
		return (ft_pushswap_error(NULL, NULL));
	if (ft_buildstacks(&stack, &argv[i]) == 0)
		return (ft_pushswap_error(&stack, NULL));
	if ((there_are_duplicates(stack.a, stack.a_count)) == 1)
		return (ft_pushswap_error(&stack, NULL));
	if ((instruction = ft_strnew(1)) == NULL)
		return (ft_pushswap_error(&stack, NULL));
	if (flag == 2 || flag == 4)
		stack_normalizer(&stack);
	if (ft_get_instructions(flag, instruction, stack) == 0)
		return (ft_pushswap_error(&stack, NULL));
	if (stack.b_count == 0 && (is_sorted(stack.a, stack.a_count) == 1))
		return (ft_pushswap_ok(&stack));
	else
		return (ft_pushswap_ko(&stack));
}

static int	checker_usage(void)
{
	ft_printf("./checker [-v] [-c] [-h] int1, int2,..\n");
	ft_printf("Checker takes integers as arguments, ");
	ft_printf("and then reads sorting instructions from the stdin.\n");
	ft_printf("If the instructions successfully sort the args ");
	ft_printf("it prints 'OK', if not it prints 'KO'.\n");
	ft_printf("If args are not integers or ");
	ft_printf("instructions invalid it will print 'Error'.\n");
	ft_printf("The [-v] flag will launch a visulizer ");
	ft_printf("of the sorting process.\n");
	ft_printf("The [-c] will print a count of how many moves were made.\n");
	ft_printf("The [-h] flag will relaunch these instructions.\n");
	return (1);
}

static int	parser(int flag, char *arg)
{
	if (arg[1] == 'h' && arg[2] == '\0')
		return (checker_usage());
	if (arg[1] == 'v' && arg[2] == '\0')
	{
		if (flag == 3)
			flag = 4;
		else
			flag = 2;
	}
	if (arg[1] == 'c' && arg[2] == '\0')
	{
		if (flag == 2)
			flag = 4;
		else
			flag = 3;
	}
	if ((arg[1] != 'h' && arg[1] != 'v'
				&& arg[1] != 'c') || (arg[2] != '\0'))
		return (0);
	return (flag);
}

int			main(int argc, char **argv)
{
	int			i;
	int			flag;

	i = 1;
	flag = 0;
	if (argc == 1)
	{
		
		return(checker_usage());
		while (1);
	}
	while (flag != 1 && i < argc && argv[i][0] == '-')
	{
		if ((flag = parser(flag, argv[i])) == 0)
			break ;
		++i;
	}
	if (flag != 1 && argc > 1 && i < argc)
		{
			
			return(checker(flag, i, argc, argv));
			while (1);}

	return (0);
}
