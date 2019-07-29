/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 00:54:43 by fcahill           #+#    #+#             */
/*   Updated: 2019/07/29 15:33:30 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pushswap.h"

int		quit_window(int i, SDL_Renderer **r, SDL_Window **window)
{
	if (i == 1)
		ft_putendl_fd("Erreur SDL_Init", 2);
	if (i == 0)
		SDL_Delay(5100);
	if (NULL != *r)
		SDL_DestroyRenderer(*r);
	if (NULL != *window)
		SDL_DestroyWindow(*window);
	SDL_QuitSubSystem(SDL_INIT_VIDEO);
	SDL_Quit();
	return (0);
}

int		init_window(SDL_Renderer **r, SDL_Window **w, t_stacks stack)
{
	if (0 != SDL_InitSubSystem(SDL_INIT_VIDEO))
		return (quit_window(1, r, w));
	*w = SDL_CreateWindow("PUSH-SWAP", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, 1240, 1080, SDL_WINDOW_SHOWN);
	if (NULL == *w)
		return (quit_window(1, r, w));
	*r = SDL_CreateRenderer(*w, 1, SDL_RENDERER_ACCELERATED);
	if (NULL == *r)
		return (quit_window(1, r, w));
	if (0 != SDL_RenderClear(*r))
		return (quit_window(1, r, w));
	draw_stacks(stack, r);
	return (1);
}
