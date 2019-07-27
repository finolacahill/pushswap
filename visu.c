/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 00:54:43 by fcahill           #+#    #+#             */
/*   Updated: 2019/07/28 00:58:55 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	stack_normalizer(t_stacks *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->a_count)
	{
		j = 0;
		while (j < stack->a_count)
		{
			if (stack->a[i] == stack->c[j])
			{
				stack->a[i] = j + 1;
				j = stack->a_count;
			}
			++j;
		}
		++i;
	}
}

int		quit_window(int i, SDL_Renderer *renderer, SDL_Window *window)
{
	if (i == 1)
		ft_putendl_fd("Erreur SDL_Init", 2);
	if (i == 0)
		SDL_Delay(5100);
	if (NULL != renderer)
		SDL_DestroyRenderer(renderer);
	if (NULL != window)
		SDL_DestroyWindow(window);
	SDL_Quit();
	return (0);
}

int		init_window(SDL_Renderer **r, SDL_Window **w, t_stacks stack)
{
	if (0 != SDL_Init(SDL_INIT_VIDEO))
		return (quit_window(1, *r, *w));
	*w = SDL_CreateWindow("PUSH-SWAP", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, 1240, 1080, SDL_WINDOW_SHOWN);
	if (NULL == *w)
		return (quit_window(1, *r, *w));
	*r = SDL_CreateRenderer(*w, -1, SDL_RENDERER_ACCELERATED);
	if (NULL == *r)
		return (quit_window(1, *r, *w));
	if (0 != SDL_RenderClear(*r))
		return (quit_window(1, *r, *w));
	draw_stacks(stack, *r);
	return (1);
}
