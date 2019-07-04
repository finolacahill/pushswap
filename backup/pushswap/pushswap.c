#include "../pushswap.h"




int			main(int argc, char **argv)
{
    
	t_stacks    stack;
	char	*instruction;
	t_list  *instructions;
	t_list  *tracker;
	int		start;

	start = 1;
	instructions = ft_lstnew(&start, 1);
	stack.b_count = 0;
	if (argc > 1)
	{
		if ((stack.a_count = ft_count_numbers(&argv[1], argc - 1)) < 0)
			return (ft_pushswap_error());
		if (ft_buildstacks(&stack, &argv[1]) == 0)
			return (ft_pushswap_error());
		if ((there_are_duplicates(stack.a, stack.a_count)) == 1)
			return (ft_pushswap_error());
//	if (ft_sort_to_ten(&stack, 'a', &instructions) == 0)
//		ft_pushswap_error();
	ft_sort_to_b(&stack, &instructions);
//	ft_sort_four(&stack, &instructions); 
//	ft_print_stacks(&stack); // mini visu to be deleted later
	tracker = instructions;
	ft_printf("\n  Moves\n---------\n");
/*	while (tracker != NULL)
	{
		ft_printf("%s\n", (char *)tracker->content);
		tracker = tracker->next;
		}
	*/}
	ft_print_stacks(&stack);
	ft_count_moves(instructions);
	return (0);
}
