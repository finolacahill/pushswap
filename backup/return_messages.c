/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_return_messages.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 11:43:44 by fcahill           #+#    #+#             */
/*   Updated: 2019/05/22 11:45:00 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void 	free_stacks(t_stacks stack)
{
	free(stack.a);
	free(stack.b);
	free(stack.c);
}

int		ft_pushswap_error(t_stacks *stack)
{
	free_stacks(*stack);
	ft_putendl_fd("Error", 2);
	return (0);
}

int		ft_pushswap_ko(t_stacks *stack)
{
	free_stacks(*stack);
	ft_printf("KO\n");
	return (0);
}

int		ft_pushswap_ok(t_stacks *stack)
{
	free_stacks(*stack);
	ft_printf("OK\n");
	return (0);
}
