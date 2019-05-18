/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 21:51:32 by fcahill           #+#    #+#             */
/*   Updated: 2019/05/05 21:51:34 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct		s_dlist
{
	int             content;
	struct t_dlist	*next;
    struct t_dlist  *prev;
}					t_dlist;

t_dlist ft_addlink(t_dlist link, int input);
void	ft_swapthem(int *stack);
void	ft_push(int *stack1, int *stack2);
void	ft_print_stacks(int *stack1, int *stack2);
void	ft_rotate(int *stack);
void	ft_revrotate(int *stack);
void	ft_move(char *instruction, int *a, int *b);
#endif
