/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 15:57:48 by fcahill           #+#    #+#             */
/*   Updated: 2019/07/28 16:13:03 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

static void		ft_print_instructions(t_list *instructions)
{
	t_list	*tracker;

	tracker = instructions->next;
	while (tracker != NULL)
	{
		ft_printf("%s\n", (char *)tracker->content);
		tracker = tracker->next;
	}
}

static void		ft_free_all(t_list *instructions, t_stacks *stack)
{
	t_list	*tracker;

	while (instructions->next != NULL)
	{
		tracker = instructions;
		instructions = instructions->next;
		if (tracker->content != NULL)
			free(tracker->content);
		free(tracker);
	}
	free(instructions->content);
	free(instructions);
	free_stacks(*stack);
}

static int		pushswap_usage(t_list *instruction)
{
	free(instruction);
	ft_printf("./push_swap int1 int2 int3..\n");
	ft_printf("Push_swap takes integers as arguments,");
	ft_printf("and sorts them between two stacks.\n");
	ft_printf("Push_swap then prints a list of ");
	ft_printf("the moves used to sort these stacks.\n");
	ft_printf("Push_swap will print 'Error' ");
	ft_printf("should arguments given be invalid.\n");
	return (0);
}

int				sort_stacks(t_stacks *stack, t_list **instructions)
{
	if (is_sorted(stack->a, stack->a_count) == 0)
	{
		if (stack->a_count <= 4)
		{
			if (ft_sort_to_four(stack, instructions, stack->a_count) == 0)
				return (0);
		}
		else
		{
			if (ft_push_to_b(stack, instructions) == 0)
				return (0);
		}
	}
	return (1);
}

int				main(int argc, char **argv)
{
	t_stacks	stack;
	t_list		*instructions;

	instructions = ft_lstnew(NULL, 0);
	stack.b_count = 0;
	if (argc == 1)
		return (pushswap_usage(instructions));
	if (argc > 1)
	{
		if ((stack.a_count = ft_count_numbers(&argv[1], argc - 1)) <= 0)
			return (ft_pushswap_error(NULL, instructions));
		if (ft_buildstacks(&stack, &argv[1]) == 0)
			return (ft_pushswap_error(&stack, instructions));
		if ((there_are_duplicates(stack.a, stack.a_count)) == 1)
			return (ft_pushswap_error(&stack, instructions));
		if (sort_stacks(&stack, &instructions) == 0)
			return (0);
		if (ft_trim(instructions) == 0)
			return (0);
		ft_print_instructions(instructions);
	}
	ft_free_all(instructions, &stack);
	return (0);
}
