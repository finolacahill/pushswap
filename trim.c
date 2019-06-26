#include "pushswap.h"

void		ft_count_moves(t_list *instructions)
{
	t_list	*tracker;
	int		i;

	i = 0;
	tracker = instructions;
	if (!(instructions))
			return ;
    while (tracker->next != NULL)
      {
		tracker = tracker->next;
		++i;
	  }
	  ft_printf("%d moves made.\n", i);
}