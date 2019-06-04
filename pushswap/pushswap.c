#include "../pushswap.h"




int			main(int argc, char **argv)
{
    
	t_stacks    stack;
	char	*instruction;

	stack.b_count = 0;
	if (argc > 1)
	{
		if ((stack.a_count = ft_count_numbers(&argv[1], argc - 1)) < 0)
			return (ft_pushswap_error());
		if (ft_buildstacks(&stack, &argv[1]) == 0)
			return (ft_pushswap_error());
		if ((there_are_duplicates(stack.a, stack.a_count)) == 1)
			return (ft_pushswap_error());
	//	ft_print_stacks(&stack); // mini visu to be deleted later
     //   ft_sort_a(&stack, 0, stack.a_count);
	
//	 
	int i = 0;
	//while(i++ < 11)
	//	ft_move("pb", &stack);
	//ft_sort_to_ten(&stack, 'a');
	ft_print_stacks(&stack);
	ft_sort_three(&stack, 'a');
//	ft_move_to_top(&stack, 'a', 4);
	ft_print_stacks(&stack); // mini visu to be deleted later
	}
	return (0);
}
