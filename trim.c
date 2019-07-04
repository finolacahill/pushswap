#include "pushswap.h"

void		ft_count_moves(t_list *instructions)
{
	t_list	*t;
	int		i;

	i = 0;
	t = instructions;
	if (!(instructions))
			return ;
    while (t->next != NULL)
      {
		t = t->next;
		++i;
	  }
	  ft_printf("%d moves made.\n", i);
}

void		ft_trim(t_list *instructions)
{
	t_list *t;
	t_list *t2;

	t = instructions;
	t2 = instructions->next;
	while (t2 != NULL && t2->next != NULL)
	{
		if (((ft_strcmp(t->next->content, "ra") == 0) && 
		(ft_strcmp(t2->next->content, "rra") == 0)) ||
			(ft_strcmp(t->next->content, "rra") == 0 
			&& ft_strcmp(t2->next->content, "ra") == 0) ||
			(ft_strcmp(t->next->content, "rb") == 0 
			&& ft_strcmp(t2->next->content, "rrb") == 0) ||
			(ft_strcmp(t->next->content, "rrb") == 0 
			&& ft_strcmp(t2->next->content, "rb") == 0) ||
			(ft_strcmp(t->next->content, "pa") == 0 
			&& ft_strcmp(t2->next->content, "pb") == 0) ||
			(ft_strcmp(t->next->content, "pb") == 0 
			&& ft_strcmp(t2->next->content, "pa") == 0))
		{
			t->next = t2->next->next;
			free(t2->next);
			free(t2);
			t2 = t->next;
		}
			t = t->next;
			if (t2 != NULL)
				t2 = t2->next;
	}

}

void	ft_trim_rotations_b(t_list *instructions)
{
	t_list *t;
	t_list *t2;
	t_list *o;
	char	i[3] = "rr\0";

	t = instructions;
	t2 = instructions->next;
	while (t2 != NULL && t2->next != NULL)
	{
		if (ft_strcmp(t->next->content, "ra") == 0)
		{
			o = t;
			while ((ft_strcmp(t->next->content, "pb") != 0)
			&& ft_strcmp(t->next->content, "rrb") != 0 &&
			ft_strcmp(t->next->content, "sb") != 0 &&
			ft_strcmp(t->next->content, "sb") != 0 &&
			ft_strcmp(t->next->content, "rb") != 0)
			{
				t = t->next;
				if (t2 != NULL)
					t2 = t2->next;
			}
			if (ft_strcmp(t->next->content, "rb") == 0)
			{
				t->next = t2->next;
				free(t2);
				free(o->content);
				o->content = i;
			}
		}
		t = t->next;
		if (t2 != NULL)
			t2 = t2->next;
	}
}

	

/*		(ft_strcmp(t->next->content, "rra") == 0 && ft_strcmp(tracker2->next->content, "ra") == 0) ||
		(ft_strcmp(t->next->content, "rb") == 0 && ft_strcmp(tracker2->next->content, "rrb") == 0) ||
		(ft_strcmp(t->next->content, "rb") == 0 && ft_strcmp(tracker2->next->content, "rrb") == 0) ||
	 	(ft_strcmp(t->next->content, "pa") && ft_strcmp(tracker2->next->content, "pb") == 0)   ||
		(ft_strcmp(t->next->content, "pb") && ft_strcmp(tracker2->next->content, "pa") == 0))*/