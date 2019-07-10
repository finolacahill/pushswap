/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 22:39:47 by fcahill           #+#    #+#             */
/*   Updated: 2019/07/10 22:39:53 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	read_repeats(t_list *t, t_list *t2)
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
		return (1);
	return (0);
}

void		ft_trim(t_list *instructions)
{
	t_list	*t;
	t_list	*t2;
	int		flag;

	t = instructions;
	t2 = instructions->next;
	while (t2 != NULL && t2->next != NULL)
	{
		if (read_repeats(t, t2) == 1)
		{
			t->next = t2->next->next;
			free(t2->next->content);
			free(t2->next);
			free(t2->content);
			free(t2);
			t2 = t->next;
			t = instructions;
			t2 = instructions->next;
		}
		else
		{
			t = t->next;
			if (t2 != NULL)
				t2 = t2->next;
		}
	}
	ft_trim_rotations(instructions);
}

static int	read_rotations(t_list *t, t_list *t2)
{
	char a[3] = "rr\0";
	char b[4] = "rrr\0";

	if (((ft_strcmp(t->content, "ra") == 0) &&
		(ft_strcmp(t->next->content, "rb") == 0)) ||
		((ft_strcmp(t->content, "rb") == 0) &&
		(ft_strcmp(t->next->content, "ra") == 0)))
	{
		free(t->content);
		t->content = a;
		return (1);
	}
	if (((ft_strcmp(t->content, "rra") == 0)
	&& (ft_strcmp(t->next->content, "rrb") == 0)) ||
		((ft_strcmp(t->content, "rrb") == 0) &&
		(ft_strcmp(t->next->content, "rra") == 0)))
	{
		free(t->content);
		t->content = b;
		return (2);
	}
	return (0);
}

void		ft_trim_rotations(t_list *instructions)
{
	t_list *t;
	t_list *t2;

	t = instructions;
	t2 = instructions->next;
	while (t2 != NULL && t2->next != NULL)
	{
		if (read_rotations(t, t2) > 0)
		{
			t->next = t2->next;
			free(t2->content);
			free(t2);
			t = instructions;
			t2 = instructions->next;
		}
		else
		{
			t = t->next;
			if (t2 != NULL)
				t2 = t2->next;
		}
	}
}
