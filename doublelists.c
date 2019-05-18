/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublelists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 21:51:46 by fcahill           #+#    #+#             */
/*   Updated: 2019/05/05 21:51:48 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_dlist     ft_addlink(t_dlist link, int input)
{
    t_dlist new;
    t_dlist *navigate;

   // if (!(new = (t_dlist)malloc(sizeof(t_dlist))))
    //    return (new);
    navigate = &link;
    while (navigate->next != NULL)
        navigate = navigate->next;
    new.content = input;
    new.prev = navigate;
    new.next = NULL;
    navigate->next = &new;
    return (new);
}


//add link end;

//add link beginning

//delete link