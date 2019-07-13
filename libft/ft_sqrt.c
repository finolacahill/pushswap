/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 19:59:35 by fcahill           #+#    #+#             */
/*   Updated: 2018/11/23 17:07:06 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int nb)
{
	int a;

	a = 2;
	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	while (a <= nb / 2)
	{
		if (((nb / a) == a) && ((nb % a) == 0))
			return (a);
		a = a + 1;
	}
	return (0);
}
