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
//checker functions
int				ft_move_and_save(char *move, t_stacks *stacks, t_list **instructions);
void	ft_move(char *move, t_stacks *stack);

void			ft_print_stacks(t_stacks *stack);
int				ft_pushswap_error(t_stacks *stack);
int				ft_pushswap_ko(t_stacks *stack);
int				ft_pushswap_ok(t_stacks *stack);
int				ft_create_stacks(int *a, int *b, char **arg);
int				ft_is_single_arg(char *arg);
int				ft_count_numbers(char **arg, int limit);
int				there_are_duplicates(int *a, int quantity_args);
int				is_sorted(int *a, int count_a);
int				ft_buildstacks(t_stacks *stack, char **args);
int				*ft_intarraycpy(int *source, int *destination, int n);

//moves
void			ft_swapthem(int *stack, int count);
void			ft_push_a(t_stacks *stack);
void			ft_push_b(t_stacks *stack);
void			ft_rotate(int *stack, int count);
void			ft_revrotate(int *stack, int count);
int			ft_trim(t_list *instructions);

//sorting
void			ft_perf_quicksort(int *array,int first,int last);
int     		ft_push_to_a(int push, t_stacks *stack, t_list**instructions);
int				ft_push_to_b(t_stacks *stack, t_list **instructions);
int     		ft_split_block_a(int block_a, t_stacks *stack, t_list **instructions);
int     		ft_split_block_b(int block_b, t_stacks *stack, t_list **instructions);
int				ft_sort_block(int push, char name, t_stacks *stack, t_list **instructions);
int				ft_sort_block_a(int push, t_stacks *stack, t_list **instructions);
int				ft_sort_block_b(int push, t_stacks *stack, t_list **instructions);
int				find_median(int *stack, int len);
int     		ft_sort_three(t_stacks *stack, t_list **moves);
int				ft_sort_two(t_stacks *stack, t_list **moves);
int				ft_sort_four(t_stacks *stack, t_list **moves);
int				ft_sort_to_four(t_stacks *stack, t_list **instructions, int block);
int				ft_push_n_to_name(t_stacks *stack, int n, char name, t_list **instructions);
//int	    		ft_push_all_to_name(t_stacks *stack, char name, t_list **instructions);
//int	    		ft_move_to_top(t_stacks *stack, char name, int index, t_list **instructions);
void			ft_count_moves(t_list *instructions);
//void	ft_trim_rotations_b(t_list *instructions);
void			ft_print_block(int *stack, int block);
int 			ft_smart_rotate_a(int block, t_stacks *stack, t_list **instructions);
int 			ft_smart_rotate_b(int block, t_stacks *stack, t_list **instructions);
//void			ft_print_instructions(t_list *instructions);
int     ft_sort_three_a(t_stacks *stack, t_list **instructions);
int     is_smallest(int *stack, int block, int placement);
int     is_largest(int *stack, int block, int placement);
int     ft_sort_three_b(t_stacks *stack, t_list **instructions);
int		ft_check_instructions(char *move);
void 	free_stacks(t_stacks stack);
int		is_split(char name, int block, int median, t_stacks *stack);
int		get_split_med(int block, int rev, int count, int *stack);
char	*ft_addchar(char *str, char c);
int	instruction_error(char *instruction);
int	ft_get_instructions(char *instruction, t_stacks stack);
int		partial_rotate(int rev, int block, t_stacks *stack, t_list **instructions);

//visu
int quit_window(int i, SDL_Renderer *renderer, SDL_Window *window);
int		draw_stacks(t_stacks stack, SDL_Renderer *renderer);
void stack_normalizer(t_stacks *stack);
int init_window(SDL_Renderer **renderer, SDL_Window *window);
#endif
