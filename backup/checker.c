/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 11:25:27 by fcahill           #+#    #+#             */
/*   Updated: 2019/07/10 12:05:49 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int			main(int argc, char **argv)
{
	t_stacks	stack;
	char		*instruction;
	int i;

	i = 0;
	stack.b_count = 0;
	if (argc > 1)
	{
		if ((stack.a_count = ft_count_numbers(&argv[1], argc - 1)) < 0)
			i = -1;
		if (i != -1 && ft_buildstacks(&stack, &argv[1]) == 0)
			i = -1;
		if ((i != -1 && there_are_duplicates(stack.a, stack.a_count)) == 1)
			{
				free(stack.a);
				free(stack.b);
				free(stack.c);
				i = -1;
			}
		while (get_next_line(0, &instruction) == 1)
		{
			if (i != -1)
				ft_move(instruction, &stack);
		}
		if (i == -1)
			return (ft_pushswap_error());
		if (stack.b_count == 0 && (is_sorted(stack.a, stack.a_count) == 1))
			return (ft_pushswap_ok());
		else
			return (ft_pushswap_ko());
	}
	
	return (0);
}
