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

int		ft_pushswap_error(void)
{
	ft_printf("Error\n");
	return (0);
}

int		ft_pushswap_ko(void)
{
	ft_printf("KO\n");
	return (0);
}

int		ft_pushswap_ok(void)
{
	ft_printf("OK\n");
	return (0);
}
