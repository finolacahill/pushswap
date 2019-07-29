/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_return_messages.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 11:43:44 by fcahill           #+#    #+#             */
/*   Updated: 2019/07/28 16:14:20 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pushswap.h"

void	free_stacks(t_stacks stack)
{
	if (stack.a)
		free(stack.a);
	if (stack.b)
		free(stack.b);
	if (stack.c)
		free(stack.c);
}

int		ft_pushswap_error(t_stacks *stack, t_list *instruction)
{
	if (instruction != NULL)
		free(instruction);
	if (stack != NULL)
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

int		instructions_error(char *instruction)
{
	free(instruction);
	return (0);
}
