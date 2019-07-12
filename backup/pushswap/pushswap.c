#include "../pushswap.h"


void			ft_print_instructions(t_list *instructions)
{
	t_list *tracker;

	tracker = instructions->next;
//	ft_printf("\n  Moves\n---------\n");
	while (tracker != NULL)
	{
		ft_printf("%s\n", (char *)tracker->content);
		tracker = tracker->next;
	}
//	free(instructions);
}

void	ft_free_list(t_list *instructions)
{
	t_list *tracker;

	while (instructions->next != NULL)
	{
		tracker = instructions;
		instructions = instructions->next;
		if (tracker->content != NULL)
			free(tracker->content);
	//	free(tracker);
	}
}


int			main(int argc, char **argv)
{
    
	t_stacks    stack;
	char	*instruction;
	t_list	*tracker;
	t_list  *instructions;
	int		start;

	start = 1;
	instructions = ft_lstnew(&start, 1);
	tracker = instructions;
	stack.b_count = 0;
	if (argc > 1)
	{
		if ((stack.a_count = ft_count_numbers(&argv[1], argc - 1)) < 0)
			return (ft_pushswap_error());
		if (ft_buildstacks(&stack, &argv[1]) == 0)
			return (ft_pushswap_error());
		if ((there_are_duplicates(stack.a, stack.a_count)) == 1)
			return (ft_pushswap_error());
	if (is_sorted(stack.a, stack.a_count) == 0)
	{
	if (stack.a_count <= 5)
		ft_sort_to_four(&stack, &instructions, stack.a_count);
		//ft_push_to_b(&stack, &instructions);
	else
		ft_push_to_b(&stack, &instructions);
	}
//	ft_sort_four(&stack, &instructions);
	ft_trim(instructions);
//	ft_trim_rotations(instructions);
	ft_print_instructions(instructions);
	
   // ft_print_stacks(&stack);
//	ft_count_moves(instructions);
	free(stack.a);
	free(stack.b);
	free(stack.c);
	}
//	ft_free_list(tracker);
	free(instructions->content);
	free(instructions);

	return (0);
}
