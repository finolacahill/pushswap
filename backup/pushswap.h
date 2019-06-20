/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 21:51:32 by fcahill           #+#    #+#             */
/*   Updated: 2019/05/22 11:47:47 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "libft/ft_printf.h"
# include "libft/libft.h"
# include "libft/get_next_line.h"

typedef struct	s_stacks
{
	int			*a;
	int			*b;
	int			*c;
	int			a_count;
	int			b_count;
}				t_stacks;
//checker functions
void			ft_move(char *move, t_stacks *stacks);
int				ft_move_and_save(char *move, t_stacks *stacks, t_list **instructions);
void			ft_print_stacks(t_stacks *stack);
int				ft_pushswap_error(void);
int				ft_pushswap_ko(void);
int				ft_pushswap_ok(void);
int				ft_create_stacks(int *a, int *b, char **arg);
int				ft_is_single_arg(char *arg);
int				ft_count_numbers(char **arg, int limit);
int				there_are_duplicates(int *a, int quantity_args);
int				is_sorted(int *a, int count_a);
int				ft_buildstacks(t_stacks *stack, char **args);
int				*ft_intarraycpy(int *source, int *destination, int n);

//moves
void			ft_swapthem(int *stack, int count);
void			ft_push(int *a, int *b, int count_a, int count_b);
void			ft_rotate(int *stack, int count);
void			ft_revrotate(int *stack, int count);

//sorting
void			ft_perf_quicksort(int *array,int first,int last);
void			ft_sort_a(t_stacks *stack, int first, int last);
void			ft_sort_b(t_stacks *stack, int first, int last);
int				find_median(t_stacks *stack, char name);
int     		ft_sort_three(t_stacks *stack, char name, t_list **moves);
int				ft_sort_two(t_stacks *stack, t_list **moves);
int				ft_sort_four(t_stacks *stack, char name, t_list **moves);
int    			ft_sort_five(t_stacks *stack, char name,  t_list **moves);
int				ft_sort_ten(t_stacks *stack, char name, int len,  t_list **moves);
int				ft_sort_to_ten(t_stacks *stack, char name, t_list **moves);
int				ft_push_n_to_name(t_stacks *stack, int n, char name, t_list **instructions);
int	    		ft_push_all_to_name(t_stacks *stack, char name, t_list **instructions);
int	    		ft_move_to_top(t_stacks *stack, char name, int index, t_list **instructions);
#endif
