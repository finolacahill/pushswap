#include "../pushswap.h"


static void		ft_print_instructions(t_list *instructions)
{
	t_list	*tracker;

	tracker = instructions->next;
	while (tracker != NULL)
	{
		ft_printf("%s\n", (char *)tracker->content);
	//	ft_putstr((char *)tracker->content);
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

int		pushswap_usage(void)
{
	ft_printf("./push_swap int1 int2 int3..\n");
	ft_printf("Push_swap takes integers as arguments, and sorts them between two stacks.\n");
	ft_printf("Push_swap then prints a list of the moves used to sort these stacks.\n");
	ft_printf("Push_swap will print 'Error' should arguments given be invalid.\n");
	return (0);
}

int				main(int argc, char **argv)
{
	t_stacks	stack;
	t_list 		*instructions;
	int			start;

	start = 1;
	instructions = ft_lstnew(NULL, 0);
	stack.b_count = 0;
	if (argc == 1)
		return(pushswap_usage());
	if (argc > 1)
	{
		if ((stack.a_count = ft_count_numbers(&argv[1], argc - 1)) < 0)
		{
			ft_putendl_fd("Error", 2);
			return (0);
		}
		if (ft_buildstacks(&stack, &argv[1]) == 0)
			return (ft_pushswap_error(&stack));
		if ((there_are_duplicates(stack.a, stack.a_count)) == 1)
			return (ft_pushswap_error(&stack));
	if (is_sorted(stack.a, stack.a_count) == 0)
	{
		if (stack.a_count <= 4)
			ft_sort_to_four(&stack, &instructions, stack.a_count);
		else
			ft_push_to_b(&stack, &instructions);
	}
	ft_trim(instructions);
	ft_print_instructions(instructions);	
	}
	ft_free_all(instructions, &stack);
	return (0);
}
