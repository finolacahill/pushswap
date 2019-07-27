/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 22:39:47 by fcahill           #+#    #+#             */
/*   Updated: 2019/07/11 11:54:54 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	read_repeats(t_list *t, t_list *t2)
{
	if (((ft_strncmp(t->next->content, "ra", 2) == 0) &&
		(ft_strncmp(t2->next->content, "rra", 3) == 0)) ||
		(ft_strncmp(t->next->content, "rra", 3) == 0
		&& ft_strncmp(t2->next->content, "ra", 2) == 0) ||
		(ft_strncmp(t->next->content, "rb", 2) == 0
		&& ft_strncmp(t2->next->content, "rrb", 3) == 0) ||
		(ft_strncmp(t->next->content, "rrb", 3) == 0
		&& ft_strncmp(t2->next->content, "rb", 2) == 0) ||
		(ft_strncmp(t->next->content, "pa", 2) == 0
		&& ft_strncmp(t2->next->content, "pb", 2) == 0) ||
		(ft_strncmp(t->next->content, "pb", 2) == 0
		&& ft_strncmp(t2->next->content, "pa", 2) == 0))
		return (1);
	return (0);
}

static void	trim_doubles(t_list *instructions)
{
	t_list	*t;
	t_list	*t2;

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
}

static int	read_rotations(t_list *t, t_list *t2)
{
	char	*a;
	int		len;

	len = 0;
	if (t->content_size != 0 && t->next->content_size != 0)
	{
	if (((ft_strcmp(t->content, "ra") == 0) &&
		(ft_strcmp(t->next->content, "rb") == 0)) ||
		((ft_strcmp(t->content, "rb") == 0) &&
		(ft_strcmp(t->next->content, "ra") == 0)))
		len = 3;
	if (((ft_strncmp(t->content, "rra", 3) == 0)
	&& (ft_strncmp(t->next->content, "rrb", 3) == 0)) ||
		((ft_strncmp(t->content, "rrb", 3) == 0) &&
		(ft_strncmp(t->next->content, "rra", 3) == 0)))
		len = 4;
	}
	if (len > 0)
	{
		free(t->content);
		if (!(t->content = (char *)malloc(sizeof(char) * len)))
			return (-1);
		if (len == 3)
			ft_strcpy(t->content, "rr\0");
		if (len == 4)
			ft_strcpy(t->content, "rrr\0");
	}
	return (len);
}

static int	ft_trim_rotations(t_list *t, t_list *t2, t_list *instructions)
{
	int		flag;

	flag = 0;
	while (t2 != NULL && t2->next != NULL)
	{
		flag = read_rotations(t, t2);
		if (flag == -1)
			return (0);
		if (flag > 0)
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
	return (1);
}

int			ft_trim(t_list *instructions)
{
	t_list	*t;
	t_list	*t2;

	t = instructions;
	t2 = instructions->next;
	trim_doubles(instructions);
	t = instructions;
	t2 = instructions->next;
	if (ft_trim_rotations(t, t2, instructions) == 0)
		return (0);
	return (1);
}
