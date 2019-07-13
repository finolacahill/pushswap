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


int				main(int argc, char **argv)
{
    
	t_stacks	stack;
	t_list 		*instructions;
	int			start;

	start = 1;
	instructions = ft_lstnew(&start, 1);
	stack.b_count = 0;
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
	if (stack.a_count <= 5)
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
