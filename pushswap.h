/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 21:51:32 by fcahill           #+#    #+#             */
/*   Updated: 2019/07/28 15:24:30 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <unistd.h>
# include <SDL2/SDL.h>
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

int				draw_stacks(t_stacks stack, SDL_Renderer **renderer);
int				find_median(int *stack, int len);
void			free_stacks(t_stacks stack);
int				ft_buildstacks(t_stacks *stack, char **args);
int				ft_check_instructions(char *move);
int				ft_count_numbers(char **arg, int limit);
int				ft_create_stacks(int *a, int *b, char **arg);
int				ft_get_instructions(int flag, char *instruction, t_stacks s);
int				*ft_intarraycpy(int *source, int *destination, int n);
int				ft_move_and_save(char *move, t_stacks *s, t_list **instruc);
void			ft_move(char *move, t_stacks *stack);
void			ft_perf_quicksort(int *array, int first, int last);
void			ft_print_stacks(t_stacks *stack);
void			ft_push_a(t_stacks *stack);
void			ft_push_b(t_stacks *stack);
int				ft_push_n_to_name(t_stacks *s, int n, char name, t_list **i);
int				ft_push_to_b(t_stacks *stack, t_list **instructions);
int				ft_pushswap_error(t_stacks *stack, t_list *instruction);
int				ft_pushswap_ko(t_stacks *stack);
int				ft_pushswap_ok(t_stacks *stack);
void			ft_rotate(int *stack, int count);
void			ft_revrotate(int *stack, int count);
int				ft_sort_block_a(int push, t_stacks *s, t_list **instructions);
int				ft_sort_block_b(int push, t_stacks *s, t_list **instructions);
int				ft_sort_two(t_stacks *stack, t_list **moves);
int				ft_sort_three_a(t_stacks *stack, t_list **instructions);
int				ft_sort_to_four(t_stacks *s, t_list **instruc, int block);
int				ft_split_block_a(int block_a, t_stacks *s, t_list **instruc);
int				ft_split_block_b(int block_b, t_stacks *s, t_list **instruc);
void			ft_swapthem(int *stack, int count);
int				ft_trim(t_list *instructions);
int				init_window(SDL_Renderer **r, SDL_Window **w, t_stacks stack);
int				instructions_error(char *instruction);
int				is_largest(int *stack, int block, int placement);
int				is_single_arg(char *arg);
int				is_smallest(int *stack, int block, int placement);
int				is_sorted(int *a, int count_a);
int				is_split(char name, int block, int median, t_stacks *stack);
int				there_are_duplicates(int *a, int quantity_args);
int				quit_window(int i, SDL_Renderer **r, SDL_Window **window);
void			stack_normalizer(t_stacks *stack);

#endif
