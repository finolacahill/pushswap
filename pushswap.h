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
# include "libft/ft_printf.h"
# include "libft/libft.h"
# include "libft/get_next_line.h"

typedef struct		s_count
{
	int             a;
	int				b;
}					t_count;

void	ft_move(char *move, int *a, int *b, t_count *count);
void	ft_print_stacks(int *a, int *b, t_count *count);
int		ft_pushswap_usage();
int		ft_pushswap_ko();
int		ft_pushswap_ok();
#endif