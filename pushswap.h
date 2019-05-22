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

typedef struct	s_count
{
	int			a;
	int			b;
}				t_count;
//checker functions
void			ft_move(char *move, int *a, int *b, t_count *count);
void			ft_print_stacks(int *a, int *b, t_count *count);
int				ft_pushswap_error(void);
int				ft_pushswap_ko(void);
int				ft_pushswap_ok(void);
int				ft_create_stacks(int *a, int *b, char **arg);
int				ft_is_single_arg(char *arg);
#endif
